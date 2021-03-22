/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:06:10 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 19:06:14 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(t_scene *s, char **line, char **buf)
{
	t_sphere *tmp;

	s->idx[4]--;
	if (!(tmp = (t_sphere*)malloc(sizeof(t_sphere)))
	|| !(buf = ft_split(*line, ' ')))
	{
		free_parsing_buf(0, line);
		check_error_exit(s, 5);
	}
	tmp->center = parse_coord(s, buf, 1, line);
	tmp->radius = ft_atof(buf[2], buf[2]) / 2;
	tmp->rgb = parse_rgb(s, buf, 3, line);
	if (tmp->rgb.r < 0 || tmp->rgb.r > 255 || tmp->rgb.g < 0 ||
	tmp->rgb.g > 255 || tmp->rgb.b < 0 || tmp->rgb.b > 255 ||
	(check_rainbow(&tmp->filter, buf[4])) == 0)
	{
		free_parsing_buf(buf, line);
		check_error_exit(s, 6);
	}
	s->sphere[(int)s->idx[4]] = tmp;
	free_parsing_buf(buf, line);
}

void	parse_plane(t_scene *s, char **line, char **buf)
{
	t_plane *tmp;

	s->idx[5]--;
	if (!(tmp = (t_plane*)malloc(sizeof(t_plane)))
	|| !(buf = ft_split(*line, ' ')))
	{
		free_parsing_buf(0, line);
		check_error_exit(s, 5);
	}
	tmp->point = parse_coord(s, buf, 1, line);
	tmp->n = parse_coord(s, buf, 2, line);
	tmp->rgb = parse_rgb(s, buf, 3, line);
	if ((is_n_valid(tmp->n)) == 0 || tmp->rgb.r < 0 ||
	tmp->rgb.r > 255 || tmp->rgb.g < 0 || tmp->rgb.g > 255 ||
	tmp->rgb.b < 0 || tmp->rgb.b > 255 ||
	(check_checkerboard(&tmp->effect, buf[4])) == 0)
	{
		free_parsing_buf(buf, line);
		check_error_exit(s, 6);
	}
	s->plane[(int)s->idx[5]] = tmp;
	free_parsing_buf(buf, line);
}

void	parse_square(t_scene *s, char **line, char **buf)
{
	t_square *tmp;

	s->idx[6]--;
	if (!(tmp = (t_square*)malloc(sizeof(t_square)))
	|| !(buf = ft_split(*line, ' ')))
	{
		free_parsing_buf(0, line);
		check_error_exit(s, 5);
	}
	tmp->center = parse_coord(s, buf, 1, line);
	tmp->n = parse_coord(s, buf, 2, line);
	tmp->side = ft_atof(buf[3], buf[3]);
	tmp->rgb = parse_rgb(s, buf, 4, line);
	if ((is_n_valid(tmp->n)) == 0 || tmp->rgb.r < 0 ||
	tmp->rgb.r > 255 || tmp->rgb.g < 0 || tmp->rgb.g > 255
	|| tmp->rgb.b < 0 || tmp->rgb.b > 255 || buf[5] != 0)
	{
		free_parsing_buf(buf, line);
		check_error_exit(s, 6);
	}
	tmp->dx = (t_vec3){ 0, 1, 0 };
	tmp->dy = (t_vec3){ 0, 0, 0 };
	s->square[(int)s->idx[6]] = tmp;
	free_parsing_buf(buf, line);
}

void	parse_cylinder(t_scene *s, char **line, char **buf)
{
	t_cylinder *tmp;

	s->idx[7]--;
	if (!(tmp = (t_cylinder*)malloc(sizeof(t_cylinder)))
	|| !(buf = ft_split(*line, ' ')))
	{
		free_parsing_buf(0, line);
		check_error_exit(s, 5);
	}
	tmp->point = parse_coord(s, buf, 1, line);
	tmp->n = parse_coord(s, buf, 2, line);
	tmp->radius = ft_atof(buf[3], buf[3]) / 2;
	tmp->height = ft_atof(buf[4], buf[4]);
	tmp->rgb = parse_rgb(s, buf, 5, line);
	if ((is_n_valid(tmp->n)) == 0 || tmp->rgb.r < 0 || tmp->rgb.r > 255
	|| tmp->rgb.g < 0 || tmp->rgb.g > 255 || tmp->rgb.b < 0 ||
	tmp->rgb.b > 255 || (check_rainbow(&tmp->filter, buf[6])) == 0)
	{
		free_parsing_buf(buf, line);
		check_error_exit(s, 6);
	}
	s->cylinder[(int)s->idx[7]] = tmp;
	free_parsing_buf(buf, line);
}

void	parse_triangle(t_scene *s, char **line, char **buf)
{
	t_triangle *tmp;

	s->idx[8]--;
	if (!(tmp = (t_triangle*)malloc(sizeof(t_triangle))) ||
	!(buf = ft_split(*line, ' ')))
	{
		free_parsing_buf(0, line);
		check_error_exit(s, 5);
	}
	tmp->a = parse_coord(s, buf, 1, line);
	tmp->b = parse_coord(s, buf, 2, line);
	tmp->c = parse_coord(s, buf, 3, line);
	tmp->rgb = parse_rgb(s, buf, 4, line);
	if (buf[5] != 0 || tmp->rgb.r < 0 || tmp->rgb.r > 255 ||
	tmp->rgb.g < 0 || tmp->rgb.g > 255 ||
	tmp->rgb.b < 0 || tmp->rgb.b > 255)
	{
		free_parsing_buf(buf, line);
		check_error_exit(s, 6);
	}
	get_triangle_edges(tmp);
	s->triangle[(int)s->idx[8]] = tmp;
	free_parsing_buf(buf, line);
}
