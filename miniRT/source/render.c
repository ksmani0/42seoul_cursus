/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:06:10 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 19:06:14 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	draw_obj_on_canvas(t_scene s, t_ray *r)
{
	int i;

	i = -1;
	while (s.sphere[++i] != 0)
		draw_sphere_on_canvas(s, r, i);
	i = -1;
	while (s.plane[++i] != 0)
		draw_plane_on_canvas(s, r, i);
	i = -1;
	while (s.square[++i] != 0)
		draw_square_on_canvas(s, r, i);
	i = -1;
	while (s.cylinder[++i] != 0)
		draw_cylinder_on_canvas(s, r, i);
	i = -1;
	while (s.triangle[++i] != 0)
		draw_triangle_on_canvas(s, r, i);
}

void	render_pixel(t_scene *s, t_ray *r, double x, double y)
{
	r->local = get_local_camera_coord(s, x, y);
	r->global = matrix_multiply_vec3(s->camera[s->i_cam]->base, r->local);
	r->t = DBL_MAX;
	r->color = 0;
	r->origin = (t_vec3){ 0, 0, 0 };
	normalize_vec3(&r->global);
	draw_obj_on_canvas(*s, r);
}

void	render_scene(t_scene *s)
{
	int		pix_x;
	int		pix_y;
	t_ray	ray;
	char	*data;

	pix_y = 0;
	make_camera_to_world_matrix(s);
	while (pix_y < s->y)
	{
		pix_x = 0;
		while (pix_x < s->x)
		{
			if (s->effect == 'a')
				render_with_antialiasing(s, &ray, (double)pix_x,
										(double)pix_y);
			else
				render_pixel(s, &ray, (double)pix_x, (double)pix_y);
			data = s->img.addr + (pix_y * s->img.len + pix_x *
					(s->img.b_pix / 8));
			*(t_uint*)data = ray.color;
			pix_x++;
		}
		pix_y++;
	}
}
