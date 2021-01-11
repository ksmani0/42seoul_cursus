/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:49:46 by seungmki          #+#    #+#             */
/*   Updated: 2020/12/02 16:47:48 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		g_hex_b[17] = "0123456789ABCDEF";
char		g_hex_s[17] = "0123456789abcdef";

int		hex_to_str(t_ullint x, t_format *list)
{
	t_ullint	temp;
	char		*hex;
	int			len;
	int			ret;

	temp = x;
	len = 0;
	while (x != 0)
	{
		x /= 16;
		len++;
	}
	ret = len;
	hex = list->spec == 'X' ? g_hex_b : g_hex_s;
	while (temp != 0)
	{
		list->num[--len] = hex[temp % 16];
		temp /= 16;
	}
	list->num[0] = ret == 0 ? '0' : list->num[0];
	return (ret != 0 ? ret : 1);
}

void	x_big_width_not_ngf(char *out, t_format *list, int len, int *i)
{
	int longer;

	if (list->flag[1] == 1 || (list->flag[2] == 1 && list->flag[6] == 0))
		return ;
	if (list->flag[5] == 0 || (list->flag[5] == 1 &&
	(list->num[0] == '0' || list->num[0] == 0)))
	{
		if (list->wid > len && len >= list->prec)
			fill_space_or_zero(i, list->wid - len, out, ' ');
		else if (list->wid > list->prec && list->prec > len)
			fill_space_or_zero(i, list->wid - list->prec, out, ' ');
	}
	else
	{
		longer = len > list->prec ? len : list->prec;
		if (list->wid > longer + 2)
			fill_space_or_zero(i, list->wid - longer - 2, out, ' ');
	}
}

int		print_sharp_x(char *out, t_format *list, int len, int i)
{
	list->size = len > list->prec ? len : list->prec;
	list->size = list->size + 2 > list->wid ? list->size + 2 : list->wid;
	if ((out = (char*)malloc(sizeof(char) * (list->size + 1))) == 0)
		return (-1);
	out[list->size] = 0;
	x_big_width_not_ngf(out, list, len, &i);
	out[i++] = '0';
	out[i++] = list->spec == 'x' ? 'x' : 'X';
	if (list->flag[1] == 1 && list->wid > len &&
	list->wid > list->prec && list->prec > len)
	{
		fill_space_or_zero(&i, list->size -
		(list->size - list->prec - 2 + len), out, '0');
	}
	else if (list->prec > len || (list->wid > len && list->flag[2] == 1))
		fill_space_or_zero(&i, list->size - len, out, '0');
	len = 0;
	while (list->num[len] != 0)
		out[i++] = list->num[len++];
	if (i < list->size)
		fill_space_or_zero(&i, list->size, out, ' ');
	list->nums += write(1, out, i);
	free(out);
	return (1);
}

void	output_x(char *out, t_format *list, int len, int i)
{
	x_big_width_not_ngf(out, list, len, &i);
	if (list->flag[1] == 1 && list->prec > len)
		fill_space_or_zero(&i, list->prec - len, out, '0');
	else if (list->prec > len || (list->wid > len && list->flag[2] == 1))
		fill_space_or_zero(&i, list->size - len, out, '0');
	len = 0;
	while (list->num[len] != 0)
		out[i++] = list->num[len++];
	if (list->flag[1] == 1 && i < list->size)
		fill_space_or_zero(&i, list->size, out, ' ');
	list->nums += write(1, out, i);
	free(out);
}

int		print_x(t_format *list)
{
	t_ullint	x;
	int			len;
	char		*out;

	if (list->flag[0] == 1 || list->flag[3] == 1)
		return (-1);
	x = check_ullint(list);
	len = hex_to_str(x, list);
	if (list->flag[5] == 1 && x != 0)
		return (print_sharp_x(0, list, len, 0));
	len = x == 0 && list->flag[6] == 1 && list->prec == 0 ? 0 : len;
	list->num[0] = x == 0 && len == 0 ? 0 : list->num[0];
	list->size = list->wid > list->prec ? list->wid : list->prec;
	list->size = len > list->size ? len : list->size;
	if ((out = (char*)malloc(sizeof(char) * (list->size + 1))) == 0)
		return (-1);
	out[list->size] = 0;
	output_x(out, list, len, 0);
	return (1);
}
