/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:43:05 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/03 00:39:48 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_num(long long temp, int fd)
{
	char c;

	if (temp > 9)
		print_num(temp / 10, fd);
	c = temp % 10 + '0';
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	long long temp;

	temp = n;
	if (n < 0)
	{
		temp *= -1;
		write(fd, "-", 1);
	}
	print_num(temp, fd);
}
