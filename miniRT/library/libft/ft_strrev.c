/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:47:31 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/08 22:50:19 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		size;
	int		i;
	char	temp;

	size = 0;
	i = 0;
	while (str[size] != 0)
		size++;
	while (i < --size)
	{
		temp = str[i];
		str[i] = str[size];
		str[size] = temp;
		i++;
	}
	return (str);
}
