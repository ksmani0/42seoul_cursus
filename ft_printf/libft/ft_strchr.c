/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:54:57 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/04 17:59:01 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char cc;

	cc = (char)c;
	while (*s != cc)
	{
		if (*s == 0)
		{
			return (NULL);
		}
		s++;
	}
	return ((char*)s);
}
