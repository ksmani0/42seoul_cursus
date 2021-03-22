/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_n_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:06:10 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 20:14:45 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	parse_coord(t_scene *s, char **buf, int i, char **line)
{
	t_vec3	result;
	char	**comma;

	if (!(comma = ft_split(buf[i], ',')))
	{
		free_parsing_buf(buf, line);
		check_error_exit(s, 5);
	}
	result.x = ft_atof(comma[0], comma[0]);
	result.y = ft_atof(comma[1], comma[1]);
	result.z = ft_atof(comma[2], comma[2]);
	i = 0;
	while (comma[i] != 0)
		free(comma[i++]);
	free(comma[i]);
	free(comma);
	return (result);
}

t_rgb	parse_rgb(t_scene *s, char **buf, int i, char **line)
{
	t_rgb	result;
	char	**comma;

	if (!(comma = ft_split(buf[i], ',')))
	{
		free_parsing_buf(buf, line);
		check_error_exit(s, 5);
	}
	result.r = ft_atof(comma[0], comma[0]);
	result.g = ft_atof(comma[1], comma[1]);
	result.b = ft_atof(comma[2], comma[2]);
	i = 0;
	while (comma[i] != 0)
		free(comma[i++]);
	free(comma[i]);
	free(comma);
	return (result);
}

void	resize_resolution(t_scene *s)
{
	int x;
	int y;

	mlx_get_screen_size(s->win.mlx_p, &x, &y);
	if (s->x > x)
		s->x = x;
	if (s->y > y)
		s->y = y;
}
