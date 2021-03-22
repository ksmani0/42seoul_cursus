/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:31:02 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 18:31:07 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	update_obj_position(t_scene *s, int i, t_vec3 new)
{
	if (i == 4)
		s->sphere[0]->center =
		vec3_add_vec3(s->sphere[0]->center, new);
	else if (i == 5)
		s->plane[0]->point =
		vec3_add_vec3(s->plane[0]->point, new);
	else if (i == 6)
		s->square[0]->center =
		vec3_add_vec3(s->square[0]->center, new);
	else if (i == 7)
		s->cylinder[0]->point =
		vec3_add_vec3(s->cylinder[0]->point, new);
	else if (i == 8)
	{
		s->triangle[0]->a =
		vec3_add_vec3(s->triangle[0]->a, new);
		s->triangle[0]->b =
		vec3_add_vec3(s->triangle[0]->b, new);
		s->triangle[0]->c =
		vec3_add_vec3(s->triangle[0]->c, new);
	}
}

void	obj_axis_translation(int key, t_scene *s, int i)
{
	t_vec3 new_pos;

	new_pos = (t_vec3){ 0, 0, 0 };
	if (key == KEY_Z)
		new_pos = (t_vec3){ -1, 0, 0 };
	else if (key == KEY_X)
		new_pos = (t_vec3){ 1, 0, 0 };
	else if (key == KEY_C)
		new_pos = (t_vec3){ 0, 1, 0 };
	else if (key == KEY_V)
		new_pos = (t_vec3){ 0, -1, 0 };
	update_obj_position(s, i, new_pos);
	render_scene(s);
	mlx_put_image_to_window(s->win.mlx_p, s->win.win_p, s->img.inst,
							0, 0);
}

void	change_camera_with_key(int key, t_scene *s)
{
	if (key == ARROW_LEFT)
	{
		if (s->i_cam > 0)
			s->i_cam--;
	}
	else if (key == ARROW_RIGHT)
	{
		if (s->i_cam < s->idx_rec[2] - 1)
			s->i_cam++;
	}
	render_scene(s);
	mlx_put_image_to_window(s->win.mlx_p, s->win.win_p, s->img.inst,
							0, 0);
}
