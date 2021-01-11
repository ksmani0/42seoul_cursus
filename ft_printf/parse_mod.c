/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:03:41 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 17:17:43 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_zero_to_prec(t_sble *sble, int prec, int i)
{
	char *temp;

	if (sble->m_len > prec)
		return (1);
	if ((temp = (char*)malloc(sizeof(char) *
	(sble->d_idx + 1 + prec + 3))) == 0)
		return (-1);
	temp[sble->d_idx + prec + 3] = 0;
	while (sble->out[++i] != 0)
		temp[i] = sble->out[i];
	i = sble->m_len;
	while (i < prec + 2)
		temp[sble->d_idx + ++i] = '0';
	free(sble->out);
	sble->out = temp;
	return (1);
}

void	input_div_pow(t_deci *pow, char *is_one)
{
	int i;
	int up;
	int temp;

	if (*is_one == 1)
	{
		*is_one = 0;
		return ;
	}
	i = 0;
	up = 0;
	while (i < pow->len)
	{
		pow->s[i] = pow->s[i] == 0 ? '0' : pow->s[i];
		if ((temp = (pow->s[i] - '0') * 2 + up) > 9)
		{
			up = temp / 10;
			pow->len = i == pow->len - 1 ? pow->len + 1 : pow->len;
		}
		else
			up = 0;
		pow->s[i++] = temp % 10 + '0';
	}
}

void	input_div_sum(char bit, t_deci *pow, t_deci *sum, int i)
{
	int up;
	int temp;

	if (bit == 0)
		return ;
	up = 0;
	sum->len = pow->len > sum->len ? pow->len : sum->len;
	while (i < sum->len)
	{
		sum->s[i] = sum->s[i] == 0 ? '0' : sum->s[i];
		pow->s[i] = pow->s[i] == 0 ? '0' : pow->s[i];
		if ((temp = (pow->s[i] - '0') + (sum->s[i] - '0') + up) > 9)
		{
			up = temp / 10;
			if (i == sum->len - 1)
				sum->len++;
		}
		else
			up = 0;
		sum->s[i++] = temp % 10 + '0';
	}
}

int		get_mod_decimal(t_sble *sble, int blen, int i, char is_one)
{
	t_deci pow;
	t_deci sum;

	ft_bzero(&pow, sizeof(pow));
	ft_bzero(&sum, sizeof(sum));
	pow.s[0] = '5';
	pow.len = 1;
	sum.s[0] = '0';
	sum.len = 1;
	while (i < blen)
	{
		input_mod_pow(&pow, &is_one);
		input_mod_sum(sble->m_bit[i++], &pow, &sum);
	}
	if ((sble->s_mod = (char*)malloc(sizeof(char) * (sum.len + 1))) == 0)
		return (-1);
	sble->s_mod[sum.len] = 0;
	i = -1;
	while (++i < sum.len)
		sble->s_mod[i] = sum.s[i];
	sble->m_len = sum.len;
	return (1);
}

int		parse_mod(t_dble *dble, t_sble *sble, int i, int j)
{
	int blen;
	int len;

	if (dble->s_int.e - 1023 >= 52 || sble->dv == 0.0 || sble->dv == -0.0)
		blen = 0;
	else
	{
		i = 0;
		blen = dble->s_int.e - 1023;
		len = blen;
		while (len <= -1)
		{
			sble->m_bit[i++] = len == -1 ? 1 : 0;
			len++;
		}
		if (len >= 0 && len <= 51)
		{
			j = len;
			blen = blen < 0 ? (blen * -1) + (52 - len) : 52 - blen;
			while (j < 52)
				sble->m_bit[i++] = ((dble->s_int.m >> (51 - j++)) & 1) + 0;
		}
	}
	return (get_mod_decimal(sble, blen, 0, 1));
}
