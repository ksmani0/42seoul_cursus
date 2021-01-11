/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 09:23:51 by seungmki          #+#    #+#             */
/*   Updated: 2020/10/16 19:45:49 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# ifndef OPEN_SIZE
#  define OPEN_SIZE 256
# endif

int	line_str_nline(char **line, char **store, int w_num);
int	line_just_str(char **line, char **store);
int	get_next_line(int fd, char **line);

int	find_nline(char *store);
int	ft_strlen(char *s);
int	free_store(int rbytes, char **store, char **line);
int	paste_malloc(char **store, char *buf, char **line);

#endif
