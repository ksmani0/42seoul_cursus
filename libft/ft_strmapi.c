/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:15:39 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/03 22:00:31 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	char			*p;
	size_t			len;
	unsigned int	i;

	if (s == 0 || f == 0)
		return ((void*)0);
	len = ft_strlen(s);
	res = (char*)malloc(sizeof(char) * len + 1);
	if (res == 0)
		return ((void*)0);
	i = 0;
	p = res;
	while (*s != 0)
	{
		*res = f(i++, *s);
		res++;
		s++;
	}
	*res = 0;
	return (p);
}
