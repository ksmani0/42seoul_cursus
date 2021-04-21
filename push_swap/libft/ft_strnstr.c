/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:34:06 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/05 15:24:26 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*bp;
	char	*lp;
	size_t	i;
	size_t	j;

	if (*little == 0)
		return ((char*)big);
	i = 0;
	while (*big != 0 && i < len)
	{
		bp = (char*)big;
		lp = (char*)little;
		j = i;
		while (*lp != 0 && *bp == *lp && j++ < len)
		{
			bp++;
			lp++;
		}
		if (*lp == 0)
			return ((char*)big);
		i++;
		big = *big != 0 ? big + 1 : big;
	}
	return (NULL);
}
