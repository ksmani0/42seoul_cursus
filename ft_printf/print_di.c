/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 20:44:49 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_space_or_zero(int *i, int limit, char *out, char s_or_z)
{
	int j;

	j = *i;
	while (j < limit)
		out[j++] = s_or_z;
	*i = j;
}

void	big_width_not_ngf(char *out, t_format *list, int len, int *i)
{
	if (list->flag[1] == 1 || (list->flag[2] == 1 && list->flag[6] == 0))
		return ;
	if ((list->num[0] == '-' && len > list->prec) || (list->num[0] != '-'
	&& list->flag[0] == 0 && list->flag[3] == 0 && len >= list->prec))
		fill_space_or_zero(i, list->wid - len, out, ' ');
	else if (list->num[0] != '-' && (list->flag[0] == 0 ||
	list->flag[3] == 0) && len > list->prec)
		fill_space_or_zero(i, list->wid - len - 1, out, ' ');
	else if (list->num[0] != '-' && len < list->prec &&
	list->flag[0] == 0 && list->flag[3] == 0)
		fill_space_or_zero(i, list->wid - list->prec, out, ' ');
	else if (list->num[0] == '-' && len <= list->prec)
		fill_space_or_zero(i, list->wid - list->prec - 1, out, ' ');
	else if (list->num[0] != '-' && (list->flag[0] == 1 ||
	list->flag[3] == 1) && len <= list->prec)
		fill_space_or_zero(i, list->wid - list->prec - 1, out, ' ');
}

void	output_di(char *out, t_format *list, int len, int i)
{
	big_width_not_ngf(out, list, len, &i);
	if (list->num[0] == '-')
		out[i++] = '-';
	else if (list->num[0] != '-' && (list->flag[0] == 1 || list->flag[3] == 1))
		out[i++] = list->flag[0] == 1 ? '+' : ' ';
	len = list->num[0] == '-' ? len - 1 : len;
	if (list->flag[1] == 1 && list->prec > len &&
	(list->num[0] == '-' || list->flag[0] == 1 || list->flag[3] == 1))
		fill_space_or_zero(&i, list->prec - len + 1, out, '0');
	else if (list->flag[1] == 1 && list->prec > len)
		fill_space_or_zero(&i, list->prec - len, out, '0');
	else if (list->prec > len || (list->wid > len && list->flag[2] == 1))
		fill_space_or_zero(&i, list->size - len, out, '0');
	len = list->num[0] == '-' ? 1 : 0;
	while (list->num[len] != 0)
		out[i++] = list->num[len++];
	if (list->flag[1] == 1 && i < list->size)
		fill_space_or_zero(&i, list->size, out, ' ');
	list->nums += write(1, out, i);
	free(out);
}

int		print_di(t_format *list)
{
	t_llint	num;
	int		len;
	char	*out;

	if (list->flag[5] == 1)
		return (-1);
	num = check_llint(list);
	len = ft_llint_to_s(num, list);
	len = num == 0 && list->flag[6] == 1 && list->prec == 0 ? 0 : len;
	list->num[0] = num == 0 && len == 0 ? 0 : list->num[0];
	list->size = list->wid > list->prec ? list->wid : list->prec;
	list->size = len > list->size ? len : list->size;
	if ((list->size == list->prec && list->prec >= len) &&
	((list->num[0] != '-' && (list->flag[0] == 1 || list->flag[3] == 1))
	|| (list->num[0] == '-')))
		list->size++;
	if ((out = (char*)malloc(sizeof(char) * (list->size + 1))) == 0)
		return (-1);
	out[list->size] = 0;
	if ((out = (char*)malloc(sizeof(char) * (list->size + 1))) == 0)
		return (-1);
	out[list->size] = 0;
	output_di(out, list, len, 0);
	return (1);
}

int		output_spec(t_format *list)
{
	if (list->spec == 'd' || list->spec == 'i')
		return (print_di(list));
	else if (list->spec == 'u')
		return (print_u(list));
	else if (list->spec == 'c')
		return (print_c(list));
	else if (list->spec == '%')
		return (print_percent(list));
	else if (list->spec == 's')
		return (print_s(list));
	else if (list->spec == 'x' || list->spec == 'X')
		return (print_x(list));
	else if (list->spec == 'o')
		return (print_o(list));
	else if (list->spec == 'e' || list->spec == 'f' || list->spec == 'g')
		return (print_feg(list));
	else if (list->spec == 'p')
		return (print_p(list));
	else if (list->spec == 'n')
		return (print_n(list, 0, 0, 0));
	return (-1);
}
