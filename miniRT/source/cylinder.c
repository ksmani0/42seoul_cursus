/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:06:10 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 19:06:14 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_cylinder_surface(t_scene *s, t_ray *r, int i)
{
	t_cylinder	*tmp;
	double		sub;

	tmp = s->cylinder[i];
	if (is_vec3_void(r->origin) != 0)
		tmp->oc = vec3_subtraction(r->origin, tmp->point);
	else
		tmp->oc = vec3_subtraction(s->camera[s->i_cam]->pos,
		tmp->point);
	sub = vec3_dot_product(r->global, tmp->n);
	tmp->a = 1 - sub * sub;
	sub = vec3_dot_product(tmp->oc, tmp->n);
	tmp->b = 2 * (vec3_dot_product(r->global, tmp->oc) -
		vec3_dot_product(r->global, tmp->n) *
		vec3_dot_product(tmp->oc, tmp->n));
	tmp->c = vec3_dot_product(tmp->oc, tmp->oc) - sub * sub -
		tmp->radius * tmp->radius;
	tmp->delta = tmp->b * tmp->b - 4 * tmp->a * tmp->c;
}

int		is_ray_intersect_cylinder(t_scene *s, t_ray *r, int i)
{
	double		t;
	t_cylinder	*tmp;

	tmp = s->cylinder[i];
	get_cylinder_surface(s, r, i);
	if (tmp->delta < 0)
		return (0);
	t = 0;
	tmp->x1 = (sqrt(tmp->delta) - tmp->b) / (2 * tmp->a);
	tmp->x2 = (-tmp->b - sqrt(tmp->delta)) / (2 * tmp->a);
	if (tmp->x1 > tmp->x2)
		t = tmp->x2;
	if (t < 0 || (t > r->t && is_vec3_void(r->origin) == 0))
		return (0);
	r->t = t;
	return (1);
}

void	get_cylinder_color(t_scene s, t_ray *r, int i)
{
	t_obj_clr obj;

	obj.p = s.cylinder[i]->p;
	obj.normal = s.cylinder[i]->n_surface;
	obj.rgb = s.cylinder[i]->rgb;
	r->color = obj_color_to_canvas(s, obj);
}

void	draw_cylinder_on_canvas(t_scene s, t_ray *r, int i)
{
	double		t;
	t_cylinder	*tmp;

	g_now_obj = s.cylinder[i]->filter == 'r' ? 'c' : 0;
	t = r->t;
	tmp = s.cylinder[i];
	if ((is_ray_intersect_cylinder(&s, r, i)) != 0)
	{
		tmp->p = vec3_add_vec3(s.camera[s.i_cam]->pos,
			scalar_multiply_vec3(r->t, r->global));
		tmp->m = vec3_dot_product(tmp->n,
			vec3_subtraction(tmp->p, tmp->point));
		tmp->center = vec3_add_vec3(tmp->point,
			scalar_multiply_vec3(tmp->m, tmp->n));
		tmp->n_surface = vec3_subtraction(tmp->p, tmp->center);
		if (tmp->m < tmp->height && tmp->m > 0)
		{
			get_cylinder_color(s, r, i);
			return ;
		}
		r->t = t;
	}
	draw_cylinder_cap(s, r, i);
}
