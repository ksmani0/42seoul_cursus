/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:24:54 by seungmki          #+#    #+#             */
/*   Updated: 2020/09/29 12:50:04 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p;
	unsigned char uc;

	p = (unsigned char*)s;
	uc = (unsigned char)c;
	while (n-- != 0)
	{
		if (*p == uc)
			return (p);
		p++;
	}
	return ((void*)0);
}
