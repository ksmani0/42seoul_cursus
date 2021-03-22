/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:07:47 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/08 23:38:46 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# define ESC 53
# define KEY_PRESS 2
# define MOUSE_PRESS 4
# define EXIT_EVENT 17

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14

# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9

# define ARROW_LEFT 123
# define ARROW_RIGHT 124

typedef union	u_dble
{
	double		value;
	struct
	{
		size_t	m : 52;
		size_t	e : 11;
		size_t	s : 1;
	}			s_int;
}				t_dble;

/*
**id:image instance address | b_pix:bit_pixel
*/
typedef struct	s_image
{
	void		*inst;
	char		*addr;
	int			len;
	int			b_pix;
	int			end;
}				t_image;

/*
**idx:scene index == idx_rec(records)
**0_scene resolution | 1_ambient | 2_camera | 3_light
**4_sphere | 5_plane | 6_square
**7_cylinder | 8_triangle
**
**x:width | y:height
**filter:zero or s or r of g or b when A has 'sepia, red, green, blue'
**effect:zero or a when anti-aliasing
*/
typedef struct	s_scene
{
	char		idx[9];
	char		idx_rec[9];
	int			x;
	int			y;
	char		filter;
	char		effect;
	short		i_cam;
	short		i_light;
	t_window	win;
	t_image		img;
	t_ambient	ambient;
	t_camera	**camera;
	t_light		**light;
	t_sphere	**sphere;
	t_plane		**plane;
	t_square	**square;
	t_cylinder	**cylinder;
	t_triangle	**triangle;
}				t_scene;

/*
****source - minirt.c****
*/
int				exit_minirt(t_window *win);
void			camera_axis_translation(int key, t_scene *s);
int				key_control(int key, t_scene *s);
int				rotate_camera_with_mouse(int click, int x, int y, t_scene *s);
void			run_minirt(t_scene s);

/*
****source - minirt2.c****
*/
void			update_obj_position(t_scene *s, int i, t_vec3 new);
void			obj_axis_translation(int key, t_scene *s, int i);
void			change_camera_with_key(int key, t_scene *s);

#endif
