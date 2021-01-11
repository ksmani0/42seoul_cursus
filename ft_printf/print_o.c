/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:38:03 by seungmki          #+#    #+#             */
/*   Updated: 2020/12/02 16:44:53 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		octal_to_str(t_ullint o, t_format *list)
{
	t_ullint	temp;
	char		*octal;
	int			len;
	int			ret;

	temp = o;
	len = 0;
	while (o != 0)
	{
		o /= 8;
		len++;
	}
	ret = len;
	octal = "01234567";
	o = temp;
	while (o != 0)
	{
		list->num[--len] = octal[o % 8];
		o /= 8;
	}
	list->num[0] = ret == 0 ? '0' : list->num[0];
	return (ret != 0 ? ret : 1);
}

void	o_big_width_not_ngf(char *out, t_format *list, int len, int *i)
{
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
		if (list->wid > len && len >= list->prec)
			fill_space_or_zero(i, list->wid - len - 1, out, ' ');
		else if (list->wid > list->prec && list->prec > len)
			fill_space_or_zero(i, list->wid - list->prec, out, ' ');
	}
}

int		print_sharp_o(char *out, t_format *list, int len, int i)
{
	list->size = len > list->prec ? len + 1 : list->prec;
	list->size = list->size > list->wid ? list->size : list->wid;
	if ((out = (char*)malloc(sizeof(char) * (list->size + 1))) == 0)
		return (-1);
	out[list->size] = 0;
	o_big_width_not_ngf(out, list, len, &i);
	out[i++] = '0';
	if (list->prec > len + 1 && list->flag[1] == 1)
		fill_space_or_zero(&i, list->prec - len, out, '0');
	else if (list->prec > len + 1)
		fill_space_or_zero(&i, list->prec - len + i, out, '0');
	len = 0;
	while (list->num[len] != 0)
		out[i++] = list->num[len++];
	if (i < list->size)
		fill_space_or_zero(&i, list->size, out, ' ');
	list->nums += write(1, out, i);
	free(out);
	return (1);
}

void	output_o(char *out, t_format *list, int len, int i)
{
	o_big_width_not_ngf(out, list, len, &i);
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

int		print_o(t_format *list)
{
	t_ullint	o;
	int			len;
	char		*out;

	if (list->flag[0] == 1 || list->flag[3] == 1)
		return (-1);
	o = check_ullint(list);
	len = octal_to_str(o, list);
	if (list->flag[5] == 1 && o != 0)
		return (print_sharp_o(0, list, len, 0));
	len = o == 0 && list->flag[6] == 1 && list->prec == 0 ? 0 : len;
	list->num[0] = o == 0 && len == 0 ? 0 : list->num[0];
	list->size = list->wid > list->prec ? list->wid : list->prec;
	list->size = len > list->size ? len : list->size;
	if ((out = (char*)malloc(sizeof(char) * (list->size + 1))) == 0)
		return (-1);
	out[list->size] = 0;
	output_o(out, list, len, 0);
	return (1);
}
