/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:06:26 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 19:06:29 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		exit_minirt(t_window *win)
{
	printf("Exit seungmki's miniRT!\n");
	mlx_destroy_window(win->mlx_p, win->win_p);
	exit(0);
}

void	camera_axis_translation(int key, t_scene *s)
{
	t_vec3 new_pos;

	new_pos = (t_vec3){ 0, 0, 0 };
	if (key == KEY_A)
		new_pos = (t_vec3){ -1, 0, 0 };
	else if (key == KEY_D)
		new_pos = (t_vec3){ 1, 0, 0 };
	else if (key == KEY_W)
		new_pos = (t_vec3){ 0, 1, 0 };
	else if (key == KEY_S)
		new_pos = (t_vec3){ 0, -1, 0 };
	else if (key == KEY_Q)
		new_pos = (t_vec3){ 0, 0, -1 };
	else if (key == KEY_E)
		new_pos = (t_vec3){ 0, 0, 1 };
	new_pos = matrix_multiply_vec3(s->camera[s->i_cam]->base, new_pos);
	s->camera[s->i_cam]->pos = vec3_add_vec3(s->camera[s->i_cam]->pos,
								new_pos);
	render_scene(s);
	mlx_put_image_to_window(s->win.mlx_p, s->win.win_p, s->img.inst,
							0, 0);
}

int		key_control(int key, t_scene *s)
{
	int i;

	i = 4;
	if (key == ESC)
		exit_minirt(&s->win);
	else if (key == KEY_A || key == KEY_D || key == KEY_W ||
	key == KEY_S || key == KEY_Q || key == KEY_E)
		camera_axis_translation(key, s);
	else if (key == KEY_Z || key == KEY_X || key == KEY_C || key == KEY_V)
	{
		while (s->idx_rec[i] == 0 && i < 8)
			i++;
		obj_axis_translation(key, s, i);
	}
	else if (key == ARROW_LEFT || key == ARROW_RIGHT)
		change_camera_with_key(key, s);
	return (0);
}

int		rotate_camera_with_mouse(int click, int x, int y, t_scene *s)
{
	t_vec3 new_n;

	(void)click;
	printf("x:%d, y:%d\n", x, y);
	new_n = get_local_camera_coord(s, (double)x, (double)y);
	new_n = matrix_multiply_vec3(s->camera[s->i_cam]->base, new_n);
	normalize_vec3(&new_n);
	s->camera[s->i_cam]->n = new_n;
	render_scene(s);
	mlx_put_image_to_window(s->win.mlx_p, s->win.win_p, s->img.inst,
							0, 0);
	return (0);
}

void	run_minirt(t_scene s)
{
	s.i_cam = s.idx_rec[2] - 1;
	s.win.win_p = mlx_new_window(s.win.mlx_p, s.x, s.y,
					"seungmki's miniRT");
	if (!(s.img.inst = mlx_new_image(s.win.mlx_p, s.x, s.y)))
		check_error_exit(&s, 7);
	if (!(s.img.addr = mlx_get_data_addr(s.img.inst,
	&s.img.b_pix, &s.img.len, &s.img.end)))
		check_error_exit(&s, 7);
	mlx_hook(s.win.win_p, KEY_PRESS, 1L << 0, key_control, &s);
	mlx_hook(s.win.win_p, MOUSE_PRESS, 1L << 0,
			rotate_camera_with_mouse, &s);
	mlx_hook(s.win.win_p, EXIT_EVENT, 0L, exit_minirt, &s.win);
	render_scene(&s);
	mlx_put_image_to_window(s.win.mlx_p, s.win.win_p, s.img.inst, 0, 0);
	mlx_loop(s.win.mlx_p);
}
