/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_npper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:35:46 by seungmki          #+#    #+#             */
/*   Updated: 2020/12/02 16:51:58 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_percent(t_format *list)
{
	char	*out;
	int		i;

	list->size = list->wid > 1 ? list->wid : 1;
	if ((out = (char*)malloc(sizeof(char) * (list->size + 1))) == 0)
		return (-1);
	out[list->size] = 0;
	i = 0;
	if (list->flag[1] == 0 && list->flag[2] == 0 && list->size > 1)
		fill_space_or_zero(&i, list->size - 1, out, ' ');
	else if (list->flag[2] == 1 && list->size > 1)
		fill_space_or_zero(&i, list->size - 1, out, '0');
	out[i++] = '%';
	if (list->flag[1] == 1 && list->size > 1)
		fill_space_or_zero(&i, list->size, out, ' ');
	write(1, out, list->size);
	free(out);
	list->nums += list->size;
	return (1);
}

int		print_n(t_format *list, t_lint *lint, int *o_int, t_sint *sint)
{
	if (list->len == 'L' || list->len == 'l')
	{
		lint = va_arg(list->ap, t_lint*);
		if (lint != 0)
			*lint = list->nums;
	}
	else if (list->len == 0 || list->len == 'H')
	{
		o_int = va_arg(list->ap, int*);
		if (o_int != 0)
			*o_int = list->nums;
	}
	else if (list->len == 'h')
	{
		sint = va_arg(list->ap, t_sint*);
		if (sint != 0)
			*sint = list->nums;
	}
	return (1);
}

size_t	ft_arr_to_s(t_ulint adrr, t_format *list)
{
	t_ulint temp;
	int		len;
	int		ret;

	len = 0;
	temp = adrr;
	while (adrr != 0)
	{
		adrr /= 16;
		len++;
	}
	len = len == 0 ? 1 : len;
	ret = len;
	adrr = temp;
	while (adrr != 0)
	{
		list->num[--len] = g_hex_s[adrr % 16];
		adrr /= 16;
	}
	list->num[0] = temp == 0 ? '0' : list->num[0];
	return (ret);
}

void	output_p(char *out, t_format *list, int len, int i)
{
	int longer;

	longer = list->prec > len ? list->prec : len;
	if (list->flag[1] == 0 && list->wid > longer + 2)
		fill_space_or_zero(&i, list->wid - longer - 2, out, ' ');
	out[i++] = '0';
	out[i++] = 'x';
	if (list->prec > len)
		fill_space_or_zero(&i, list->size - len, out, '0');
	len = 0;
	while (list->num[len] != 0)
		out[i++] = list->num[len++];
	if (i < list->size)
		fill_space_or_zero(&i, list->size, out, ' ');
	list->nums += write(1, out, i);
	free(out);
}

int		print_p(t_format *list)
{
	t_ulint	adrr;
	int		len;
	char	*out;

	if (list->flag[0] == 1 || list->flag[2] == 1 ||
	list->flag[3] == 1 || list->flag[5] == 1)
		return (-1);
	adrr = (t_ulint)va_arg(list->ap, void*);
	len = ft_arr_to_s(adrr, list);
	len = adrr == 0 && list->flag[6] == 1 && list->prec == 0 ? 0 : len;
	list->num[0] = adrr == 0 && len == 0 ? 0 : list->num[0];
	list->size = len > list->prec ? len : list->prec;
	list->size = list->size + 2 > list->wid ? list->size + 2 : list->wid;
	if ((out = (char*)malloc(sizeof(char) * (list->size + 1))) == 0)
		return (-1);
	out[list->size] = 0;
	output_p(out, list, len, 0);
	return (1);
}
