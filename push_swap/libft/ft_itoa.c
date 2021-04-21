/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 00:26:14 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/05 15:55:13 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	make_min(char *num)
{
	num[0] = '-';
	num[1] = '2';
	num[2] = '1';
	num[3] = '4';
	num[4] = '7';
	num[5] = '4';
	num[6] = '8';
	num[7] = '3';
	num[8] = '6';
	num[9] = '4';
	num[10] = '8';
	num[11] = 0;
}

static void	make_num(char *arr, int n, int len)
{
	if (n < 0)
	{
		n *= -1;
		arr[0] = '-';
	}
	arr[len] = 0;
	while (n > 0)
	{
		arr[--len] = n % 10 + '0';
		n /= 10;
	}
}

static int	num_size(int n)
{
	int i;

	if (n == -2147483648)
		return (11);
	else if (n == 0)
		return (1);
	i = n < 0 ? 1 : 0;
	n = n < 0 ? n * -1 : n;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*arr;
	int		len;

	len = num_size(n);
	arr = (char*)malloc(sizeof(char) * (len + 1));
	if (arr == 0)
		return ((void*)0);
	if (n == -2147483648)
		make_min(arr);
	else if (n == 0)
	{
		arr[0] = '0';
		arr[1] = 0;
	}
	else
		make_num(arr, n, len);
	return (arr);
}
