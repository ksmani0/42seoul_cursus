/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:09:12 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 19:38:01 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		is_intersect_inside_triangle(t_scene s, int i, t_sub_plane *pl)
{
	double p;
	double q;
	t_vec3 p0;

	p0 = vec3_subtraction(pl->p, s.triangle[i]->a);
	p = get_p_parameter(s.triangle[i], p0);
	q = get_q_parameter(s.triangle[i], p0);
	if (p >= 0 && p <= 1 && q >= 0 && q <= 1 && p + q >= 0 && p + q <= 1)
		return (1);
	return (0);
}

int		is_ray_intersect_triagle(t_scene *s, t_ray *r, int i,
								t_sub_plane *pl)
{
	double t;

	t = r->t;
	if ((is_ray_intersect_plane(s, r, pl)) != 0 &&
	(get_intersection_of_plane(s, r, pl)) != 0 &&
	(is_intersect_inside_triangle(*s, i, pl)) != 0)
	{
		if (pl->den > 0)
			pl->n = scalar_multiply_vec3(-1, pl->n);
		return (1);
	}
	r->t = t;
	return (0);
}

int		is_shadow_in_triangle(t_scene s, t_ray *r, int i)
{
	t_sub_plane sub_pl;

	sub_pl.point = s.triangle[i]->a;
	sub_pl.n = vec3_cross_product(s.triangle[i]->e1, s.triangle[i]->e0);
	if ((is_ray_intersect_triagle(&s, r, i, &sub_pl)) == 0)
		return (0);
	if (between_light_n_obj(s.light[s.i_light]->pos, sub_pl.p,
		r->origin) == 0)
		return (0);
	return (1);
}

void	draw_triangle_on_canvas(t_scene s, t_ray *r, int i)
{
	t_sub_plane	sub_pl;
	t_obj_clr	obj;

	g_now_obj = 0;
	sub_pl.point = s.triangle[i]->a;
	sub_pl.n = vec3_cross_product(s.triangle[i]->e1, s.triangle[i]->e0);
	if ((is_ray_intersect_triagle(&s, r, i, &sub_pl)) == 0)
		return ;
	obj.p = sub_pl.p;
	obj.normal = sub_pl.n;
	obj.rgb = s.triangle[i]->rgb;
	r->color = obj_color_to_canvas(s, obj);
}

void	get_triangle_edges(t_triangle *t)
{
	t->e0 = vec3_subtraction(t->b, t->a);
	t->e1 = vec3_subtraction(t->c, t->a);
	t->det = t->e0.x * t->e1.y - t->e0.y * t->e1.x;
	t->equa = 0;
	if (t->det == 0)
	{
		t->det = t->e0.y * t->e1.z - t->e1.y * t->e0.z;
		t->equa = 1;
	}
	if (t->det == 0)
	{
		t->det = t->e0.x * t->e1.z - t->e0.z * t->e1.x;
		t->equa = 2;
	}
}
