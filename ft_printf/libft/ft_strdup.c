/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:52:24 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/05 15:17:10 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*arr;
	char	*p;

	size = ft_strlen(s);
	arr = (char*)malloc(sizeof(char) * (size + 1));
	if (arr == 0)
		return ((void*)0);
	p = arr;
	while (*s != 0)
		*arr++ = *s++;
	*arr = 0;
	return (p);
}
