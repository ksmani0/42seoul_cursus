/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 11:35:46 by seungmki          #+#    #+#             */
/*   Updated: 2020/12/07 21:15:52 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_u(char *out, t_format *list, int len, int i)
{
	if (list->flag[1] == 0 && list->wid > list->prec && list->wid > len)
	{
		if (list->prec > len)
			fill_space_or_zero(&i, list->wid - list->prec, out, ' ');
		else if ((list->flag[6] == 1 && len >= list->prec) ||
		(list->flag[2] == 0 && list->flag[6] == 0))
			fill_space_or_zero(&i, list->wid - len, out, ' ');
	}
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

int		print_u(t_format *list)
{
	t_ullint	num;
	int			len;
	char		*out;

	if (list->flag[0] == 1 || list->flag[3] == 1 || list->flag[5] == 1)
		return (-1);
	num = check_ullint(list);
	len = ft_ullint_to_s(num, list);
	len = num == 0 && list->flag[6] == 1 && list->prec == 0 ? 0 : len;
	list->num[0] = num == 0 && len == 0 ? 0 : list->num[0];
	list->size = list->wid > list->prec ? list->wid : list->prec;
	list->size = len > list->size ? len : list->size;
	if ((out = (char*)malloc(sizeof(char) * (list->size + 1))) == 0)
		return (-1);
	out[list->size] = 0;
	output_u(out, list, len, 0);
	return (1);
}

void	g_meet_sharp(t_format *list, t_sble *sble)
{
	int i;

	if (!(list->flag[5] == 0 && list->num[1] == 'g'))
		return ;
	i = sble->m_idx;
	while (i != sble->d_idx && sble->out[i] == '0')
	{
		sble->m_idx--;
		i--;
	}
	if (sble->d_idx == sble->m_idx)
		list->prec = 0;
}

int		get_e_int(t_format *list, t_sble *tp, int i)
{
	if (tp->out[1] == '0' && tp->m_len >= 1 && tp->dv != 0 && tp->dv != -0.0)
		tp->esign = '-';
	if (tp->esign == '+')
		tp->e_int = tp->d_len > 1 ? tp->d_len - 1 : 0;
	else if (tp->esign == '-' && (i = tp->d_idx + 1))
	{
		tp->e_int = tp->d_idx - 1;
		while (tp->out[i++] == '0')
			tp->e_int--;
		tp->e_int--;
	}
	tp->d_idx = tp->e_int < 0 ? tp->e_int * -1 + tp->d_idx : 1;
	tp->m_len = tp->m_len + tp->e_int;
	if ((round_feg(list, tp)) == -1)
		return (-1);
	if (tp->out[tp->d_idx] != '0' || tp->dv == 0 || tp->dv == -0.0)
		return (1);
	if (tp->esign == '-' && tp->out[tp->d_idx] == '0' &&
	tp->out[tp->d_idx - 1] == '1')
		tp->esign = tp->e_int + 1 == 0 ? '+' : '-';
	++tp->e_int;
	return (1);
}

int		find_e_x(t_format *list, t_sble tp, int *x)
{
	int i;
	int j;

	if ((tp.out = (char*)malloc(sizeof(char) *
	(tp.d_len + tp.m_len + 2))) == 0)
		return (-1);
	tp.out[tp.d_len + tp.m_len + 1] = 0;
	tp.out[0] = '0';
	list->prec = *x;
	tp.esign = '+';
	tp.d_idx = tp.d_len;
	i = 1;
	j = tp.d_len - 1;
	while (i <= tp.d_len)
		tp.out[i++] = tp.s_div[j--];
	j = -1;
	while (++j < tp.m_len)
		tp.out[i++] = tp.s_mod[j];
	if ((get_e_int(list, &tp, 0)) == -1)
		return (-1);
	*x = tp.e_int;
	free(tp.out);
	return (1);
}
