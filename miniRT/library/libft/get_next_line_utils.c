/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 09:28:00 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/16 19:33:08 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			find_nline(char *store)
{
	int num;

	num = 0;
	while (*store != 0)
	{
		if (*store++ == '\n')
			return (num);
		++num;
	}
	return (-1);
}

int			free_store(int rbytes, char **store, char **line)
{
	if (rbytes == 0 && *store == 0)
	{
		if ((*line = (char*)malloc(sizeof(char) * 1)) == 0)
			return (-1);
		*(*line) = 0;
		return (0);
	}
	free(*store);
	*store = 0;
	return (-1);
}

int			paste_malloc(char **store, char *buf, char **line,
						int rbytes)
{
	char	*temp;
	char	*tp;
	char	*sp;

	if (*store != 0)
		rbytes += (int)ft_strlen((const char*)*store);
	if ((temp = (char*)malloc(sizeof(char) * (rbytes + 1))) == 0)
		return (free_store(-1, store, line));
	tp = temp;
	sp = *store;
	if (sp != 0)
	{
		while (*sp != 0)
			*temp++ = *sp++;
		free(*store);
	}
	while (*buf != 0)
		*temp++ = *buf++;
	*temp = 0;
	*store = tp;
	return (1);
}
