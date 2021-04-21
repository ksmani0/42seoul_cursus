/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:43:08 by seungmki          #+#    #+#             */
/*   Updated: 2020/09/29 15:20:54 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*arr;
	char	*p;

	if (s1 == 0 || s2 == 0)
		return ((void*)0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	arr = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
	if (arr == 0)
		return ((void*)0);
	p = arr;
	p[len1 + len2] = 0;
	while (*s1 != 0)
	{
		*p++ = *s1++;
	}
	while (*s2 != 0)
	{
		*p++ = *s2++;
	}
	return (arr);
}
