/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:36:04 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/05 15:44:22 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	long	res;
	int		minus;

	res = 0;
	minus = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
		minus = *s++ == '-' ? -1 : 1;
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		if (res < 0)
			return (minus == 1 ? -1 : 0);
		s++;
	}
	return ((int)res * minus);
}
