/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 09:25:07 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/16 19:42:09 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

int	line_str_nline(char **line, char **store, int w_num);
int	line_just_str(char **line, char **store);
int	get_next_line(int fd, char **line);

int	find_nline(char *store);
int	ft_strlen(char *s);
int	free_store(int rbytes, char **store, char **line);
int	paste_malloc(char **store, char *buf, char **line);

#endif
