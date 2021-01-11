/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:12:07 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 17:36:17 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_div_decimal(t_sble *sble, int i, char is_one)
{
	t_deci pow;
	t_deci sum;

	ft_bzero((void*)&pow, sizeof(pow));
	ft_bzero((void*)&sum, sizeof(sum));
	pow.s[0] = '1';
	pow.len = 1;
	sum.s[0] = '0';
	sum.len = 1;
	while (i >= 0)
	{
		input_div_pow(&pow, &is_one);
		input_div_sum(sble->d_bit[i--], &pow, &sum, 0);
	}
	if ((sble->s_div = (char*)malloc(sizeof(char) * (sum.len + 1))) == 0)
		return (-1);
	sble->s_div[sum.len] = 0;
	i = -1;
	while (++i < sum.len)
	{
		sble->s_div[i] = sum.s[i];
		sble->d_len++;
	}
	return (1);
}

int		parse_div(t_dble *dble, t_sble *sble)
{
	int blen;
	int i;
	int j;

	if (dble->s_int.e - 1023 <= -1)
		blen = 0;
	else
	{
		blen = dble->s_int.e - 1023;
		sble->d_bit[0] = 1;
		i = 0;
		j = 0;
		while (j < blen && j < 52)
			sble->d_bit[++i] = (dble->s_int.m >> (51 - j++) & 1) + 0;
		if (blen > 52)
		{
			j = 0;
			while (j++ < blen - 52)
				sble->d_bit[++i] = 0;
		}
		blen++;
	}
	sble->sign = dble->s_int.s == 1 ? '-' : '+';
	return (get_div_decimal(sble, blen - 1, 1));
}

int		check_inf_nan(t_dble *db, t_format *list, int i, int len)
{
	char	*s;

	if (db->s_int.e != 2047)
		return (0);
	if (db->s_int.s == 0 && db->s_int.e == 2047 && db->s_int.m == 0
	&& (list->flag[0] == 1 || list->flag[3] == 1) && (len = 4))
		s = list->flag[0] == 1 ? "+inf" : " inf";
	else if ((db->s_int.s == 0 && db->s_int.e == 2047 && db->s_int.m == 0)
	|| (db->s_int.e == 2047 && db->s_int.m >= 1))
		s = db->s_int.m >= 1 ? "nan" : "inf";
	else if (db->s_int.s == 1 && db->s_int.e == 2047 &&
	db->s_int.m == 0 && (len = 4))
		s = "-inf";
	if (list->flag[1] == 0 && list->wid > len)
	{
		while (i++ < list->wid - len)
			list->nums += write(1, " ", 1);
	}
	list->nums += write(1, s, len);
	if (list->flag[1] == 1 && list->wid > len)
	{
		while (i++ < list->wid - len)
			list->nums += write(1, " ", 1);
	}
	return (1);
}

int		free_sble(int error_or_not, t_sble *sble)
{
	free(sble->s_div);
	free(sble->s_mod);
	free(sble->out);
	free(sble->e);
	return (error_or_not);
}

int		print_feg(t_format *list)
{
	t_dble	dble;
	t_sble	sble;
	char	is_f;

	if (list->len == 'h' || list->len == 'H' || list->len == 'L')
		return (-1);
	ft_bzero((void*)&dble, sizeof(dble));
	dble.value = va_arg(list->ap, double);
	if ((check_inf_nan(&dble, list, 0, 3)) == 1)
		return (1);
	ft_bzero((void*)&sble, sizeof(sble));
	sble.dv = dble.value;
	if (!(parse_div(&dble, &sble)) || !(parse_mod(&dble, &sble, 0, 0)))
		return (free_sble(-1, &sble));
	is_f = list->spec == 'f' ? 1 : 0;
	if (list->spec == 'g' && (get_g_str(list, &sble, 6, &is_f)) == -1)
		return (-1);
	if (list->spec == 'e' && is_f == 0)
		return (get_e_str(list, &sble, 0));
	return (get_f_str(list, &sble));
}
