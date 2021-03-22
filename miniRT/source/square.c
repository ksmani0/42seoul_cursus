/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:06:10 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 19:33:25 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		is_intersect_inside_square(t_scene s, t_sub_plane *pl, int i)
{
	t_square	*tmp;
	double		x;
	double		y;

	tmp = s.square[i];
	tmp->dx = get_axis('x');
	tmp->dy = vec3_cross_product(pl->n, tmp->dx);
	if ((is_vec3_void(tmp->dy)) == 0)
	{
		tmp->dx = get_axis('y');
		tmp->dy = vec3_cross_product(pl->n, tmp->dx);
	}
	normalize_vec3(&tmp->dx);
	normalize_vec3(&tmp->dy);
	x = vec3_dot_product(tmp->dx, vec3_subtraction(pl->p, tmp->center));
	y = vec3_dot_product(tmp->dy, vec3_subtraction(pl->p, tmp->center));
	if ((ft_double_abs(x)) > tmp->side || (ft_double_abs(y)) > tmp->side)
		return (0);
	return (1);
}

int		is_shadow_in_square(t_scene s, t_ray *r, int i)
{
	t_sub_plane sub_pl;

	sub_pl.point = s.square[i]->center;
	sub_pl.n = s.square[i]->n;
	if ((is_ray_intersect_plane(&s, r, &sub_pl)) == 0)
		return (0);
	if ((get_intersection_of_plane(&s, r, &sub_pl)) == 0)
		return (0);
	if ((is_intersect_inside_square(s, &sub_pl, i)) == 0)
		return (0);
	if ((between_light_n_obj(s.light[s.i_light]->pos, sub_pl.p,
		r->origin)) == 0)
		return (0);
	return (1);
}

void	draw_square_on_canvas(t_scene s, t_ray *r, int i)
{
	double		t;
	t_sub_plane	sub_pl;
	t_obj_clr	obj;

	g_now_obj = 0;
	t = r->t;
	sub_pl.point = s.square[i]->center;
	sub_pl.n = s.square[i]->n;
	if ((is_ray_intersect_plane(&s, r, &sub_pl)) == 0 ||
	(get_intersection_of_plane(&s, r, &sub_pl)) == 0 ||
	(is_intersect_inside_square(s, &sub_pl, i)) == 0)
	{
		r->t = t;
		return ;
	}
	if (sub_pl.den > 0)
		sub_pl.n = scalar_multiply_vec3(-1, sub_pl.n);
	obj.p = sub_pl.p;
	obj.normal = sub_pl.n;
	obj.rgb = s.square[i]->rgb;
	r->color = obj_color_to_canvas(s, obj);
}
