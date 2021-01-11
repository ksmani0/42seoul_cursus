/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:24:22 by seungmki          #+#    #+#             */
/*   Updated: 2020/12/02 16:43:14 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_s(t_format *list, t_uchar *s, int len)
{
	int		i;
	int		size;
	char	c;

	i = 0;
	c = list->flag[2] == 1 ? '0' : ' ';
	if (list->flag[1] == 0 && list->wid > len)
	{
		while (i++ < list->wid - len)
			write(1, &c, 1);
	}
	size = i > 0 ? i - 1 : 0;
	size += write(1, s, len);
	i = 0;
	if (list->flag[1] == 1 && list->wid > len)
	{
		while (i++ < list->wid - len)
			write(1, " ", 1);
	}
	size = i > 0 ? size + (i - 1) : size;
	list->nums += size;
}

void	make_nul_s(t_uchar *nul_s)
{
	nul_s[0] = '(';
	nul_s[1] = 'n';
	nul_s[2] = 'u';
	nul_s[3] = 'l';
	nul_s[4] = 'l';
	nul_s[5] = ')';
	nul_s[6] = 0;
}

int		print_null(t_format *list)
{
	t_uchar nul_s[7];
	int		len;

	make_nul_s(nul_s);
	len = 6;
	if (list->flag[6] == 1 && list->prec < len)
		len = list->prec < len ? list->prec : len;
	output_s(list, nul_s, len);
	return (1);
}

int		print_s(t_format *list)
{
	t_uchar	*s;
	int		len;

	if (list->flag[0] == 1 || list->flag[3] == 1 || list->flag[5] == 1)
		return (-1);
	if (list->len == 'l' || list->len == 'L')
		return (print_ls(list));
	if ((s = (t_uchar*)va_arg(list->ap, char*)) == 0)
		return (print_null(list));
	len = ft_strlen((const char*)s);
	if (list->flag[6] == 1 && list->prec < len)
		len = list->prec;
	output_s(list, s, len);
	return (1);
}
