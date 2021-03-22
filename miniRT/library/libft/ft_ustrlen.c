/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 00:06:57 by seungmki          #+#    #+#             */
/*   Updated: 2020/11/21 00:07:05 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ustrlen(const t_uchar *s)
{
	size_t len;

	if (s == 0)
		return (0);
	len = 0;
	while (*s != 0)
	{
		s++;
		len++;
	}
	return (len);
}
