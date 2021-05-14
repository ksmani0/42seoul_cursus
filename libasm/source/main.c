/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:14:07 by seungmki          #+#    #+#             */
/*   Updated: 2021/04/21 20:16:24 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

char *g_str[6] = {
	"Hello, I'm seungmki!",
	"this is my libasm test program.",
	"Let's count the numbers~",
	"1",
	"23456789",
	"Bye bye~"
};

void	test_read_n_write_n_strlen(void)
{
	int		i;
	int		num;
	char	buf[256];

	i = -1;
	printf("============ ft_write.s, ft_strlen.s ============\n");
	while (++i < 6)
	{
		write(1, g_str[i], strlen(g_str[i]));
		printf("\n!!!mine is below!!!\n");
		ft_write(1, g_str[i], ft_strlen(g_str[i]));
		printf("\n");
	}
	printf("\n\n======== ft_read.s, ft_write.s, ft_strlen.s ========\n");
	num = ft_read(0, buf, 256);
	buf[num] = 0;
	ft_write(1, buf, ft_strlen(buf));
}

void	test_strcpy(void)
{
	int		i;
	char	buf[64];

	i = -1;
	printf("\n\n============ ft_strcpy.s ============\n");
	while (++i < 6)
	{
		ft_strcpy(buf, g_str[i]);
		printf("%s VS %s\n", g_str[i], buf);
	}
}

void	test_strdup(void)
{
	int		i;
	char	*same;

	i = -1;
	printf("\n\n============ ft_strdup.s ============\n");
	while (++i < 6)
	{
		same = ft_strdup(g_str[i]);
		printf("%s\n", same);
		free(same);
	}
}

int		main(void)
{
	test_read_n_write_n_strlen();
	test_strcpy();
	printf("\n\n========== ft_strcmp.s ==========\n");
	printf("origin:%d, mine:%d\n", strcmp(g_str[0], g_str[5]),
			ft_strcmp(g_str[0], g_str[5]));
	printf("origin:%d, mine:%d\n", strcmp(g_str[4], g_str[3]),
			ft_strcmp(g_str[4], g_str[3]));
	printf("origin:%d, mine:%d\n", strcmp(g_str[3], g_str[5]),
			ft_strcmp(g_str[3], g_str[5]));
	printf("origin:%d, mine:%d\n", strcmp(g_str[2], g_str[2]),
			ft_strcmp(g_str[2], g_str[2]));
	test_strdup();
	return (0);
}
