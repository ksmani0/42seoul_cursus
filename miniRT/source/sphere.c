/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:06:10 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 19:06:14 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		is_ray_intersect_sphere(t_scene *s, t_ray *r, int i)
{
	t_sphere	*tmp;
	double		oc_tmp;

	tmp = s->sphere[i];
	if (is_vec3_void(r->origin) != 0)
		tmp->oc = vec3_subtraction(tmp->center, r->origin);
	else
	{
		tmp->oc = vec3_subtraction(tmp->center,
		s->camera[s->i_cam]->pos);
	}
	tmp->p_oc = vec3_dot_product(tmp->oc, r->global);
	if (tmp->p_oc < 0)
		return (0);
	oc_tmp = vec3_self_dot_sqrt(tmp->oc);
	tmp->d = sqrt(oc_tmp * oc_tmp - tmp->p_oc * tmp->p_oc);
	if (tmp->d > tmp->radius)
		return (0);
	return (1);
}

int		is_shadow_in_sphere(t_scene s, t_ray *r, int i)
{
	t_sphere *tmp;

	tmp = s.sphere[i];
	if ((is_ray_intersect_sphere(&s, r, i)) != 0)
	{
		r->t = tmp->p_oc - sqrt(tmp->radius * tmp->radius
			- tmp->d * tmp->d);
		tmp->p = vec3_add_vec3(r->origin,
			scalar_multiply_vec3(r->t, r->global));
		if (between_light_n_obj(s.light[s.i_light]->p_shad,
			tmp->p, r->origin) != 0)
			return (1);
	}
	return (0);
}

void	draw_sphere_on_canvas(t_scene s, t_ray *r, int i)
{
	double		t;
	t_obj_clr	obj;
	t_sphere	*tmp;

	g_now_obj = s.sphere[i]->filter == 'r' ? 's' : 0;
	if ((is_ray_intersect_sphere(&s, r, i)) == 0)
		return ;
	tmp = s.sphere[i];
	t = tmp->p_oc - sqrt(tmp->radius * tmp->radius - tmp->d * tmp->d);
	if (t > r->t)
		return ;
	r->t = t;
	obj.p = vec3_add_vec3(s.camera[s.i_cam]->pos,
			scalar_multiply_vec3(r->t, r->global));
	obj.normal = vec3_subtraction(obj.p, tmp->center);
	obj.rgb = tmp->rgb;
	obj.center = tmp->center;
	r->color = obj_color_to_canvas(s, obj);
}
