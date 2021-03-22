/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:08:32 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 19:08:35 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_parsing_buf(char **buf, char **line)
{
	int i;

	i = 0;
	while (buf != 0 && buf[i] != 0)
		free(buf[i++]);
	if (buf != 0)
		free(buf[i]);
	free(buf);
	free(*line);
	*line = 0;
}

void	parse_resolution(t_scene *scene, char **line)
{
	char **buf;

	if (!(buf = ft_split(*line, ' ')))
	{
		free_parsing_buf(0, line);
		check_error_exit(scene, 6);
	}
	scene->x = ft_atoi(buf[1]);
	scene->y = ft_atoi(buf[2]);
	if (scene->x <= 0 || scene->y <= 0 ||
	(check_antialising(&scene->effect, buf[3])) == 0)
	{
		free_parsing_buf(buf, line);
		check_error_exit(scene, 5);
	}
	free_parsing_buf(buf, line);
}

void	parse_ambient(t_scene *s, char **line)
{
	char **buf;

	if (!(buf = ft_split(*line, ' ')))
	{
		free_parsing_buf(0, line);
		check_error_exit(s, 6);
	}
	s->ambient.inten = ft_atof(buf[1], buf[1]);
	s->ambient.rgb = parse_rgb(s, buf, 2, line);
	if (s->ambient.inten < 0.0 || s->ambient.inten > 1.0 ||
	s->ambient.rgb.r < 0 || s->ambient.rgb.r > 255 ||
	s->ambient.rgb.g < 0 || s->ambient.rgb.g > 255 ||
	s->ambient.rgb.b < 0 || s->ambient.rgb.b > 255 ||
	check_filter(s, buf[3]) == 0)
	{
		free_parsing_buf(buf, line);
		check_error_exit(s, 5);
	}
	free_parsing_buf(buf, line);
}

void	parse_camera(t_scene *s, char **line, char **buf)
{
	t_camera *tmp;

	s->idx[2]--;
	if (!(tmp = (t_camera*)malloc(sizeof(t_camera)))
	|| !(buf = ft_split(*line, ' ')))
	{
		free_parsing_buf(0, line);
		check_error_exit(s, 6);
	}
	tmp->pos = parse_coord(s, buf, 1, line);
	tmp->n = parse_coord(s, buf, 2, line);
	tmp->fov = ft_atof(buf[3], buf[3]);
	if (tmp->fov < 0 || tmp->fov > 180 || (is_n_valid(tmp->n)) == 0
	|| buf[4] != 0)
	{
		free_parsing_buf(buf, line);
		check_error_exit(s, 5);
	}
	tmp->fov = tan((tmp->fov * M_PI) / 360);
	s->camera[(int)s->idx[2]] = tmp;
	free_parsing_buf(buf, line);
}

void	parse_light(t_scene *s, char **line, char **buf)
{
	t_light *tmp;

	s->idx[3]--;
	if (!(tmp = (t_light*)malloc(sizeof(t_light))) ||
	!(buf = ft_split(*line, ' ')))
	{
		free_parsing_buf(0, line);
		check_error_exit(s, 5);
	}
	tmp->pos = parse_coord(s, buf, 1, line);
	tmp->inten = ft_atof(buf[2], buf[2]);
	tmp->rgb = parse_rgb(s, buf, 3, line);
	if (tmp->inten < 0 || tmp->inten > 1 || tmp->rgb.r < 0 ||
	tmp->rgb.r > 255 || tmp->rgb.g < 0 || tmp->rgb.g > 255 ||
	tmp->rgb.b < 0 || tmp->rgb.b > 255 || check_parallel(buf[4]) == 0)
	{
		free_parsing_buf(buf, line);
		check_error_exit(s, 6);
	}
	tmp->parallel = buf[4] == 0 ? (t_vec3){ 0, 0, 0 } :
	parse_parallel(s, buf, 4, line);
	s->light[(int)s->idx[3]] = tmp;
	free_parsing_buf(buf, line);
}
