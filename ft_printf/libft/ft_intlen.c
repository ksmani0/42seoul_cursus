/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:34:19 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 00:03:52 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int n)
{
	size_t		len;
	t_ullint	temp;

	if (n == 0)
		return (1);
	len = 0;
	temp = n < 0 ? n * -1 : n;
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	return (len);
}
