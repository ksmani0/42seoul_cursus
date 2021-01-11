/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:56:10 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 17:58:41 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_lc(t_format *list, t_uchar *out, t_uchar *lc_s, int len)
{
	int i;

	i = 0;
	if (list->flag[1] == 0 && list->wid > len)
		fill_space_or_zero(&i, list->size - len, (char*)out, ' ');
	len = 0;
	while (lc_s[len] != 0)
		out[i++] = lc_s[len++];
	if (list->flag[1] == 1 && list->wid > 1)
		fill_space_or_zero(&i, list->size, (char*)out, ' ');
	list->nums += write(1, out, i);
	free(lc_s);
	free(out);
}

int		input_lc_s(wint_t lc, t_uchar *lc_s)
{
	int len;

	len = 1;
	if (lc < 128 && !(lc_s[0] = 0))
		lc_s[0] = (t_uchar)lc;
	else if (lc < 2048 && (len = 2))
		lc_s[0] = (lc >> 6) + 192;
	else if (lc < 65536 && (len = 3))
		lc_s[0] = (lc >> 12) + 224;
	else if (lc < 2097152 && (len = 4))
	{
		lc_s[0] = (lc >> 18) + 240;
		lc_s[1] = ((lc >> 12) & 63) + 128;
	}
	if (len > 2)
		lc_s[len - 2] = ((lc >> 6) & 63) + 128;
	if (len > 1)
		lc_s[len - 1] = (lc & 63) + 128;
	return (len);
}

int		print_lc(t_format *list)
{
	wint_t	lc;
	t_uchar	*lc_s;
	t_uchar *out;
	int		len;

	lc = va_arg(list->ap, wint_t);
	if ((lc_s = (t_uchar*)malloc(sizeof(t_uchar) * 5)) == 0)
		return (-1);
	ft_bzero((void*)lc_s, 5);
	len = input_lc_s(lc, lc_s);
	list->size = list->wid > len ? list->wid : len;
	if ((out = (t_uchar*)malloc(sizeof(t_uchar) * (list->size + 1))) == 0)
	{
		free(lc_s);
		return (-1);
	}
	out[list->size] = 0;
	output_lc(list, out, lc_s, len);
	return (1);
}

void	output_c(t_format *list, t_uchar *out, t_uchar c)
{
	int i;

	i = 0;
	if (list->flag[1] == 0 && list->wid > 1)
		fill_space_or_zero(&i, list->size - 1, (char*)out, ' ');
	out[i++] = c;
	if (list->flag[1] == 1 && list->wid > 1)
		fill_space_or_zero(&i, list->size, (char*)out, ' ');
	list->nums += write(1, out, i);
	free(out);
}

int		print_c(t_format *list)
{
	t_uchar c;
	t_uchar	*out;

	if (list->flag[0] == 1 || list->flag[2] == 1
	|| list->flag[3] == 1 || list->flag[5] == 1)
		return (-1);
	if (list->len == 'l')
		return (print_lc(list));
	c = check_ullint(list);
	list->size = list->wid > 1 ? list->wid : 1;
	if ((out = (t_uchar*)malloc(sizeof(t_uchar) * (list->size + 1))) == 0)
		return (-1);
	out[list->size] = 0;
	output_c(list, out, c);
	return (1);
}
