/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:09:40 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/08 23:09:45 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

extern char		g_now_obj;

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct	s_rgb
{
	double		r;
	double		g;
	double		b;
}				t_rgb;

/*
**mlx_p:mlx_ptr, mlx instance address | win_p:win_ptr
*/
typedef struct	s_window
{
	void		*mlx_p;
	void		*win_p;
	int			key;
}				t_window;

/*
**inten:intensity
*/
typedef struct	s_ambient
{
	double		inten;
	t_rgb		rgb;
}				t_ambient;

typedef struct	s_matrix
{
	t_vec3		vx;
	t_vec3		vy;
	t_vec3		vz;
}				t_matrix;

/*
**pos:position | n:normal
**base:camera to world matrix
*/
typedef struct	s_camera
{
	t_vec3		pos;
	t_vec3		n;
	t_matrix	base;
	double		fov;
}				t_camera;

/*
**p_shad:pos_shadow | inten:intensity
*/
typedef struct	s_light
{
	t_vec3		pos;
	t_vec3		p_shad;
	double		inten;
	t_rgb		rgb;
	t_vec3		parallel;
}				t_light;

/*
**p_x:pixel_x | p_y:pixel_y
*/
typedef struct	s_ray
{
	int			p_x;
	int			p_y;
	t_vec3		local;
	t_vec3		global;
	t_vec3		origin;
	int			color;
	double		t;
}				t_ray;

typedef struct	s_axis
{
	t_vec3		x;
	t_vec3		y;
	t_vec3		z;
}				t_axis;

/*
**p_oc:Intersection of ray and sphere
**oc:vector that sphere center - origin
**filter:for rainbow
*/
typedef struct	s_sphere
{
	t_vec3		center;
	double		radius;
	t_rgb		rgb;
	double		p_oc;
	double		d;
	t_vec3		p;
	t_vec3		oc;
	t_vec3		n;
	char		filter;
}				t_sphere;

/*
**effect:for checkerboard
*/
typedef struct	s_plane
{
	t_vec3		point;
	t_vec3		n;
	t_rgb		rgb;
	char		effect;
}				t_plane;

/*
**den:denominator obtained by dot product of the plane direction vector
**and the direction of the ray passing through each pixel
**po:The direction vector po by subtracting the coordinates
**from the light source coordinates
*/
typedef struct	s_sub_palne
{
	t_vec3		point;
	t_vec3		n;
	double		den;
	double		num;
	t_vec3		l;
	t_vec3		p;
	t_vec3		po;
}				t_sub_plane;

typedef struct	s_square
{
	t_vec3		center;
	t_vec3		n;
	double		side;
	t_rgb		rgb;
	t_vec3		dx;
	t_vec3		dy;
}				t_square;

/*
**delta:in other words discriminant
**filter:for rainbow
*/
typedef struct	s_cylinder
{
	t_vec3		point;
	t_vec3		n;
	t_rgb		rgb;
	double		radius;
	double		height;
	double		a;
	double		b;
	double		c;
	double		x1;
	double		x2;
	double		m;
	double		delta;
	t_vec3		oc;
	t_vec3		p;
	t_vec3		center;
	t_vec3		n_surface;
	char		filter;
}				t_cylinder;

/*
**det:determinant | equa:equation | e0:b-a
**e1:c-a | e2: a-c | p0:ray intersection
*/
typedef struct	s_triangle
{
	t_vec3		a;
	t_vec3		b;
	t_vec3		c;
	t_rgb		rgb;
	double		det;
	char		equa;
	t_vec3		e0;
	t_vec3		e1;
	t_vec3		e2;
	t_vec3		p0;
}				t_triangle;

/*
**p:intersection point
*/
typedef struct	s_obj_clr
{
	t_vec3		p;
	t_vec3		center;
	t_vec3		normal;
	t_vec3		light;
	t_vec3		ray;
	t_rgb		rgb;
}				t_obj_clr;

#endif
