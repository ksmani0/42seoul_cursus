/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_f_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 17:14:43 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	round_up(t_sble *sble, int prec)
{
	int i;
	int up;
	int temp;

	i = sble->d_idx + prec;
	up = 1;
	sble->m_idx = sble->d_idx + prec;
	while (i >= 0 && up == 1)
	{
		temp = (sble->out[i] - '0') + up;
		sble->out[i--] = temp % 10 + '0';
		up = temp <= 9 ? 0 : up;
	}
}

void	rounding_meet_five(t_sble *sble, int prec)
{
	int i;
	int not_zero;

	i = sble->d_idx + prec + 2;
	not_zero = 0;
	while (sble->out[i] != 0 && not_zero == 0)
	{
		if (sble->out[i++] != '0')
			not_zero = 1;
	}
	if (not_zero == 1)
		round_up(sble, prec);
	else if (not_zero == 0 &&
	(sble->out[sble->d_idx + prec] - '0') % 2 != 0)
		round_up(sble, prec);
	else
		sble->m_idx = sble->d_idx + prec;
}

int		round_feg(t_format *list, t_sble *sble)
{
	int prec;

	prec = list->flag[6] == 0 ? 6 : list->prec;
	if ((prec >= 1076 || prec > sble->m_len) &&
	(add_zero_to_prec(sble, prec, -1)) == 0)
		return (-1);
	if ((list->flag[6] == 0 && sble->m_len < 6) || (sble->m_len < prec))
	{
		sble->m_idx = list->flag[6] == 0 ?
		sble->d_idx + 6 : sble->d_idx + prec;
	}
	if (sble->out[sble->d_idx + prec + 1] < '5')
		sble->m_idx = sble->d_idx + prec;
	else if (sble->out[sble->d_idx + prec + 1] > '5')
		round_up(sble, prec);
	else
		rounding_meet_five(sble, prec);
	list->prec = prec;
	return (1);
}

int		make_out_str(t_sble *sble)
{
	int i;
	int j;

	i = 1;
	j = sble->d_len - 1;
	sble->d_idx = sble->d_len;
	if ((sble->out = (char*)malloc(sizeof(char) *
		(sble->d_len + 1 + sble->m_len + 1))) == 0)
		return (-1);
	sble->out[sble->d_len + 1 + sble->m_len] = 0;
	sble->out[0] = '0';
	while (i <= sble->d_len)
		sble->out[i++] = sble->s_div[j--];
	j = -1;
	while (++j < sble->m_len)
		sble->out[i++] = sble->s_mod[j];
	return (1);
}

int		get_f_str(t_format *list, t_sble *sble)
{
	if ((make_out_str(sble)) == -1 || (round_feg(list, sble)) == -1)
		return (free_sble(-1, sble));
	g_meet_sharp(list, sble);
	list->size = sble->out[0] == '0' ? sble->m_idx : sble->m_idx + 1;
	list->size = sble->sign == '-' ? list->size + 1 : list->size;
	if ((sble->sign == '+') && (list->flag[0] == 1 || list->flag[3] == 1))
		list->size++;
	if (list->prec > 0 || (list->flag[5] == 1 && list->flag[6] == 1))
		list->size++;
	output_feg(list, sble, 0, 0);
	list->nums += (list->size > list->wid ? list->size : list->wid);
	return (free_sble(1, sble));
}
