/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 13:25:13 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/05 15:14:02 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	size;
	size_t	i;

	if (s == 0)
		return ((void*)0);
	arr = (char*)malloc(sizeof(char) * (len + 1));
	if (arr == 0)
		return ((void*)0);
	size = ft_strlen(s);
	if (size <= start)
	{
		arr[0] = 0;
		return (arr);
	}
	arr[len] = 0;
	i = 0;
	s += start;
	while (i < len)
		arr[i++] = *s++;
	return (arr);
}
