/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 09:23:51 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/16 19:34:56 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_str_nline(char **line, char **store, int w_num)
{
	int		len;
	char	*lp;
	char	*sp;
	char	*temp;

	if ((*line = (char*)malloc(sizeof(char) * (w_num + 1))) == 0)
		return (free_store(-1, store, line));
	lp = *line;
	sp = *store;
	while (w_num-- > 0)
		*lp++ = *sp++;
	*lp = 0;
	sp = sp + 1;
	len = ft_strlen(sp);
	if ((lp = (char*)malloc(sizeof(char) * (len + 1))) == 0)
		return (free_store(-1, store, line));
	temp = lp;
	while (*sp != 0)
		*lp++ = *sp++;
	*lp = 0;
	free(*store);
	*store = temp;
	return (1);
}

int	line_just_str(char **line, char **store)
{
	int		len;
	char	*lp;
	char	*sp;

	len = ft_strlen(*store);
	if ((*line = (char*)malloc(sizeof(char) * (len + 1))) == 0)
		return (free_store(-1, store, line));
	lp = *line;
	sp = *store;
	while (*sp != 0)
		*lp++ = *sp++;
	*lp = 0;
	free(*store);
	*store = 0;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		rd_buf[BUFFER_SIZE + 1];
	static char	*store = 0;
	int			rbytes;
	int			w_num;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((rbytes = read(fd, rd_buf, BUFFER_SIZE)) > 0)
	{
		rd_buf[rbytes] = 0;
		if ((paste_malloc(&store, rd_buf, line)) != 1)
			return (-1);
		if ((w_num = find_nline(store)) >= 0)
			return (line_str_nline(line, &store, w_num));
	}
	if (rbytes == 0 && store != 0 && (w_num = find_nline(store)) >= 0)
		return (line_str_nline(line, &store, w_num));
	else if (rbytes == 0 && store != 0)
		return (line_just_str(line, &store));
	return (free_store(rbytes, &store, line));
}
