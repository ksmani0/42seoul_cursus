/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_feg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/12/02 16:32:41 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		change_e_num(t_sble *sble, int elen, char *tp)
{
	if (sble->out[sble->d_idx] != '0' || sble->dv == 0 || sble->dv == -0.0)
		return (1);
	if (sble->esign == '-' && sble->out[sble->d_idx] == '0' &&
	sble->out[sble->d_idx - 1] == '1')
		sble->esign = sble->e_int + 1 == 0 ? '+' : '-';
	else if (sble->esign == '+' && sble->out[sble->d_idx] == '0' &&
	sble->out[sble->d_idx - 1] == '1')
	{
		elen = ft_intlen(sble->e_int + 1);
		elen = elen == 1 ? 2 : elen;
		if ((tp = (char*)malloc(sizeof(char) * (elen + 3))) == 0)
			return (-1);
		free(sble->e);
		sble->e = tp;
	}
	fill_e_num(sble, ++sble->e_int, elen);
	sble->d_idx--;
	sble->m_idx--;
	return (1);
}

void	output_feg_sign(t_format *list, t_sble *sble, int *i)
{
	if ((sble->sign == '-' || list->flag[0] == 1) && (*i = *i + 1))
		sble->sign == '+' ? write(1, "+", 1) : write(1, "-", 1);
	else if ((sble->sign == '-' || list->flag[3] == 1) && (*i = *i + 1))
		sble->sign == '+' ? write(1, " ", 1) : write(1, "-", 1);
}

void	output_decimal(t_format *list, t_sble *sble, int *i, int j)
{
	j = sble->out[0] == '0' ? 1 : 0;
	j = list->spec == 'e' ? sble->d_idx : j;
	while (j <= sble->d_idx)
		*i += write(1, &sble->out[j++], 1);
	if (list->prec > 0 || (list->flag[5] == 1 && list->flag[6] == 1))
		*i += write(1, ".", 1);
	while (j <= sble->m_idx)
		*i += write(1, &sble->out[j++], 1);
	if (list->spec == 'e')
	{
		j = ft_strlen(sble->e) - 1;
		while (j >= 0)
			*i += write(1, &sble->e[j--], 1);
	}
}

void	output_feg(t_format *list, t_sble *sble, int i, int temp)
{
	if (list->flag[1] == 1 || ((sble->sign == '-' || list->flag[0] == 1
	|| list->flag[3] == 1) && list->size >= list->wid)
	|| (list->wid > list->size && list->flag[2] == 1))
		output_feg_sign(list, sble, &i);
	if (list->wid > list->size && list->flag[1] == 0 &&
	list->flag[2] == 0)
	{
		while (i++ < list->wid - list->size)
			write(1, " ", 1);
		output_feg_sign(list, sble, &i);
	}
	else if (list->wid > list->size && list->flag[2] == 1)
	{
		temp = sble->sign == '-' || list->flag[0] == 1
		|| list->flag[3] == 1 ? list->size - 1 : list->size;
		while (i++ < list->wid - temp)
			write(1, "0", 1);
	}
	output_decimal(list, sble, &i, 0);
	if (list->wid > list->size && list->flag[1] == 1)
	{
		while (i++ < list->wid)
			write(1, " ", 1);
	}
}

int		get_g_str(t_format *list, t_sble *sble, int p, char *is_f)
{
	int x;

	if (list->flag[6] == 1)
		p = list->prec == 0 ? 1 : list->prec;
	x = p < 1 ? 0 : p - 1;
	if ((p == 0 && (find_e_x(list, *sble, &x)) == -1) ||
	(p >= 1 && (find_e_x(list, *sble, &x)) == -1))
		return (-1);
	list->num[1] = 'g';
	if (p > x && x >= -4 && (*is_f = 1))
	{
		list->prec = p - 1 - x;
		list->flag[6] = list->prec >= 0 ? 1 : 0;
		list->prec = list->prec >= 0 ? list->prec : 0;
		list->spec = 'f';
		return (1);
	}
	list->prec = p - 1;
	list->flag[6] = list->prec >= 0 ? 1 : 0;
	list->prec = list->prec >= 0 ? list->prec : 0;
	list->spec = 'e';
	return (1);
}
