/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:34:44 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/03 00:36:53 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dp;
	unsigned char *sp;

	if (dst == 0 || src == 0)
		return ((void*)0);
	dp = (unsigned char*)dst;
	sp = (unsigned char*)src;
	if (dp <= sp)
	{
		while (len-- != 0)
			*dp++ = *sp++;
	}
	else
	{
		dp += len;
		sp += len;
		while (len-- != 0)
			*--dp = *--sp;
	}
	return (dst);
}
