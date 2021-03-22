/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:06:10 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 20:26:40 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		is_shadow_in_cap(t_scene s, t_ray *shad_r, int i)
{
	t_sub_plane	sub_pl;
	t_cylinder	*tmp;

	tmp = s.cylinder[i];
	if (tmp->m != 0 && tmp->m > tmp->height)
		sub_pl.point = vec3_add_vec3(tmp->point,
			scalar_multiply_vec3(tmp->height, tmp->n));
	else
		sub_pl.point = tmp->point;
	sub_pl.n = tmp->n;
	if ((is_ray_intersect_cap(&s, shad_r, i, &sub_pl)) != 0)
		if ((between_light_n_obj(s.light[s.i_light]->pos, sub_pl.p,
		shad_r->origin)) != 0)
			return (1);
	return (0);
}

int		is_shadow_in_cylinder(t_scene s, t_ray *shad_r, int i)
{
	t_cylinder *tmp;

	tmp = s.cylinder[i];
	tmp->m = 0;
	if (is_ray_intersect_cylinder(&s, shad_r, i) != 0)
	{
		tmp->p = vec3_add_vec3(shad_r->origin,
			scalar_multiply_vec3(shad_r->t, shad_r->global));
		if ((between_light_n_obj(s.light[s.i_light]->pos, tmp->p,
		shad_r->origin)) != 0)
		{
			tmp->m = vec3_dot_product(tmp->n,
				vec3_subtraction(tmp->p, tmp->point));
			if (tmp->m > 0 && tmp->m < tmp->height)
				return (1);
		}
	}
	if ((is_shadow_in_cap(s, shad_r, i)) != 0)
		return (1);
	return (0);
}

t_vec3	get_nearest_cap(t_scene s, int i)
{
	t_vec3		vec3[2];
	t_vec3		top_cap;
	double		distance[2];
	t_cylinder	*tmp;

	tmp = s.cylinder[i];
	top_cap = vec3_add_vec3(tmp->point,
		scalar_multiply_vec3(tmp->height, tmp->n));
	vec3[0] = vec3_subtraction(s.camera[s.i_cam]->pos, tmp->point);
	vec3[1] = vec3_subtraction(s.camera[s.i_cam]->pos, top_cap);
	distance[0] = vec3_self_dot_sqrt(vec3[0]);
	distance[1] = vec3_self_dot_sqrt(vec3[1]);
	if (distance[0] > distance[1])
		return (top_cap);
	return (tmp->point);
}

int		is_ray_intersect_cap(t_scene *s, t_ray *r, int i, t_sub_plane *pl)
{
	double length;

	if ((is_ray_intersect_plane(s, r, pl)) == 0)
		return (0);
	if (get_intersection_of_plane(s, r, pl) == 0)
		return (0);
	length = vec3_self_dot_sqrt(vec3_subtraction(pl->p, pl->point));
	if (length >= s->cylinder[i]->radius)
		return (0);
	if (pl->den > 0)
		pl->n = scalar_multiply_vec3(-1, pl->n);
	return (1);
}

void	draw_cylinder_cap(t_scene s, t_ray *r, int i)
{
	double		t;
	t_obj_clr	obj;
	t_cylinder	*tmp;
	t_sub_plane	sub_pl;

	t = r->t;
	tmp = s.cylinder[i];
	if (tmp->m != 0 && tmp->m > tmp->height)
		sub_pl.point = vec3_add_vec3(tmp->point,
		scalar_multiply_vec3(tmp->height, tmp->n));
	else
		sub_pl.point = get_nearest_cap(s, i);
	sub_pl.n = tmp->n;
	if (is_ray_intersect_cap(&s, r, i, &sub_pl) != 0)
	{
		obj.p = sub_pl.p;
		obj.normal = sub_pl.n;
		obj.rgb = tmp->rgb;
		r->color = obj_color_to_canvas(s, obj);
	}
	r->t = t;
}
