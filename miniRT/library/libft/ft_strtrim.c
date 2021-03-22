/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:21:49 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/05 15:31:32 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		fi;
	int		bi;
	char	*arr;

	if (s1 == 0 || set == 0)
		return ((void*)0);
	fi = 0;
	while (s1[fi] != 0 && ft_strchr(set, s1[fi]))
		fi++;
	bi = ft_strlen(s1 + fi);
	while (bi != 0 && ft_strchr(set, s1[fi + bi - 1]))
		bi--;
	arr = (char*)malloc(sizeof(char) * (bi + 1));
	if (arr == 0)
		return ((void*)0);
	arr[bi] = 0;
	while (bi-- != 0)
		arr[bi] = s1[fi + bi];
	return (arr);
}
