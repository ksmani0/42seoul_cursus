/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:03:17 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/08 17:31:26 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	multiply_two(char *s)
{
	int i;
	int up;
	int tmp;

	i = 0;
	up = 0;
	while (s[i] != 0 && i < 179)
	{
		if ((tmp = (s[i] - '0') * 2 + up) > 9)
			up = 1;
		else
			up = 0;
		s[i++] = (tmp % 10) + '0';
	}
	if (s[0] == '0')
	{
		i = -1;
		while (s[++i] != 0)
			s[i] = s[i + 1];
	}
	return (up == 1 ? '1' : '0');
}

float	bit_to_float(t_sflt *f, int i, int j)
{
	t_uflt	uf;
	int		exp;

	ft_bzero(&uf, sizeof(t_uflt));
	if (f->d_len == 1 && f->d_bit[0] == '0')
	{
		while (f->m_bit[i] != '1' && f->m_bit[i] != 0)
			i++;
		exp = (i + 1) * -1;
	}
	else
		exp = f->d_len - 1;
	uf.s_uint.s = f->sign == '-' ? 1 : 0;
	uf.s_uint.e = exp + 127;
	i = exp;
	while (i > 0 && j-- >= 0)
		uf.s_uint.m += (f->d_bit[--i] & 1) << j;
	i = i < 0 ? i * -1 : i;
	while (f->m_bit[i] != 0 && j-- >= 0)
		uf.s_uint.m += (f->m_bit[i++] & 1) << j;
	return (uf.value);
}

float	make_f_bit(long div, t_sflt *f)
{
	f->d_bit[0] = '0';
	if (div < 0 && (f->sign = '-'))
		div *= -1;
	while (div != 0 && f->d_len < 129)
	{
		f->d_bit[f->d_len++] = div % 2 + '0';
		div /= 2;
	}
	f->d_len = f->d_len == 0 ? 1 : f->d_len;
	f->m_bit[0] = '0';
	while (f->m_num[0] != 0 && f->m_len < 179)
		f->m_bit[f->m_len++] = multiply_two(f->m_num);
	f->m_len = f->m_len == 0 ? 1 : f->m_len;
	return (bit_to_float(f, 0, 23));
}

float	ft_atof(char *s, char *p)
{
	float	f;
	long	div;
	t_sflt	flt;

	div = ft_atoi(s);
	while (*p != '.' && *p != 0)
		p++;
	if (*p == 0 || s == p || *(p + 1) < '0' || *(p + 1) > '9')
		return (*p == 0 ? (float)div : -0.0);
	ft_bzero(&flt, sizeof(t_sflt));
	p++;
	while (*p >= '0' && *p <= '9')
		flt.m_num[flt.i_mod++] = *p++;
	ft_strrev(flt.m_num);
	if (flt.i_mod == 1 && flt.m_num[0] == '0')
		return (*s == '-' && div == 0 ? -0.0 : (float)div);
	f = make_f_bit(div, &flt);
	f = *s == '-' && f >= 0 ? f * -1 : f;
	return (f);
}
