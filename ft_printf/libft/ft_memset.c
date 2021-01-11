/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:09:10 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/03 01:06:05 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	uc;
	unsigned char	*p;
	size_t			i;

	if (b == 0)
		return ((void*)0);
	uc = (unsigned char)c;
	p = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		*p++ = uc;
		i++;
	}
	return (b);
}
