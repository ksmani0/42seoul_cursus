/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_n_shadow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:06:10 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 20:22:36 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		between_light_n_obj(t_vec3 light, t_vec3 point, t_vec3 origin)
{
	t_vec3 shad_ray;
	t_vec3 light_ray;
	double sqrt_global;
	double sqrt_shad;

	shad_ray = vec3_subtraction(point, origin);
	light_ray = vec3_subtraction(light, origin);
	sqrt_shad = vec3_self_dot_sqrt(shad_ray);
	sqrt_global = vec3_self_dot_sqrt(light_ray);
	if (sqrt_shad > 0.0001 && sqrt_shad < sqrt_global)
		return (1);
	return (0);
}

int		is_obj_shaded(t_scene s, t_ray *shad_r)
{
	int i;

	i = -1;
	while (s.sphere[++i] != 0)
		if ((is_shadow_in_sphere(s, shad_r, i)) != 0)
			return (1);
	i = -1;
	while (s.plane[++i] != 0)
		if ((is_shadow_in_plane(s, shad_r, i)) != 0)
			return (1);
	i = -1;
	while (s.square[++i] != 0)
		if ((is_shadow_in_square(s, shad_r, i)) != 0)
			return (1);
	i = -1;
	while (s.cylinder[++i] != 0)
		if ((is_shadow_in_cylinder(s, shad_r, i)) != 0)
			return (1);
	i = -1;
	while (s.triangle[++i] != 0)
		if ((is_shadow_in_triangle(s, shad_r, i)) != 0)
			return (1);
	return (0);
}

void	obj_disruption_for_shading(t_light *l, t_obj_clr *obj)
{
	t_vec3	light_dir;
	t_vec3	lp;

	lp = vec3_subtraction(l->pos, obj->p);
	if (g_now_obj == 's' || g_now_obj == 'c')
		apply_rainbow_pattern(obj);
	if (g_now_obj == 'p')
		apply_checkerboard(obj);
	if (is_vec3_void(l->parallel) != 0)
	{
		light_dir = l->parallel;
		light_dir = scalar_multiply_vec3(-1, light_dir);
		normalize_vec3(&light_dir);
		l->p_shad = scalar_multiply_vec3(vec3_dot_product(light_dir,
					lp), light_dir);
	}
	else
	{
		light_dir = lp;
		l->p_shad = l->pos;
		normalize_vec3(&light_dir);
	}
	obj->light = light_dir;
}

t_vec3	parse_parallel(t_scene *s, char **buf, int i, char **line)
{
	char	**comma;
	t_vec3	result;
	char	*tmp;

	tmp = buf[i];
	while (*tmp != ':' && *tmp != 0)
		tmp++;
	comma = 0;
	if (*tmp != ':' || !(comma = ft_split(++tmp, ',')))
	{
		free_parsing_buf(buf, line);
		check_error_exit(s, 5);
	}
	result.x = ft_atoi(comma[0]);
	result.y = ft_atoi(comma[1]);
	result.z = ft_atoi(comma[2]);
	i = 0;
	while (comma[i] != 0)
		free(comma[i++]);
	free(comma[i]);
	free(comma);
	normalize_vec3(&result);
	return (result);
}

int		check_parallel(char *s)
{
	if (s == 0 || ft_strncmp(s, "parallel", 8) == 0)
		return (1);
	return (0);
}
