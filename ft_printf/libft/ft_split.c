/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:19:27 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/05 15:15:09 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_word_num(char const *s, char c)
{
	size_t num;

	num = 0;
	while (*s != 0)
	{
		if (*s != c && *s != 0)
		{
			num++;
			while (*s != c && *s != 0)
				s++;
		}
		else if (*s != 0)
			s++;
	}
	return (num);
}

static void		ft_strcpy(char *arr, char *p, char const *s)
{
	while (p < s)
		*arr++ = *p++;
	*arr = 0;
}

static void		do_split(char **arr, char const *s, char c)
{
	size_t	i;
	char	*p;

	if (*s == 0)
		return ;
	i = 0;
	while (*s != 0)
	{
		if (*s != c && *s != 0)
		{
			p = (char*)s;
			while (*s != c && *s != 0)
				s++;
			arr[i] = (char*)malloc(sizeof(char) * (s - p + 1));
			ft_strcpy(arr[i], p, s);
			i++;
		}
		else if (*s != 0)
			s++;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	num;

	if (s == 0)
		return ((void*)0);
	num = get_word_num(s, c);
	arr = (char**)malloc(sizeof(char*) * (num + 1));
	if (arr == 0)
		return ((void*)0);
	arr[num] = 0;
	if (num == 0)
		return (arr);
	do_split(arr, s, c);
	return (arr);
}
