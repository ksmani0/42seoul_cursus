/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:39:19 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/08 23:39:22 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <float.h>
# include <errno.h>
# include "libft.h"
# include "mlx.h"
# include "geometry.h"
# include "scene.h"

/*
****source - main.c****
*/
void	free_each_obj(t_scene *s, int i);
void	free_scene(t_scene *s);
void	check_error_exit(t_scene *scene, int error);
void	guide_output(t_scene *scene);
int		main(int ac, char **av);

/*
****source - parse_scene.c****
*/
void	count_scene_obj(t_scene *scene, char *line);
void	malloc_scene_obj(t_scene *s);
void	fill_each_obj(t_scene *scene, char **line);
void	fill_scene(char *file, t_scene *scene);
void	read_rt(char *file, t_scene *scene);

/*
****source - parse_scene2.c****
*/
void	free_parsing_buf(char **buf, char **line);
void	parse_resolution(t_scene *scene, char **line);
void	parse_ambient(t_scene *s, char **line);
void	parse_camera(t_scene *s, char **line, char **buf);
void	parse_light(t_scene *s, char **line, char **buf);

/*
****source - parse_scene3.c****
*/
void	parse_sphere(t_scene *s, char **line, char **buf);
void	parse_plane(t_scene *s, char **line, char **buf);
void	parse_square(t_scene *s, char **line, char **buf);
void	parse_cylinder(t_scene *s, char **line, char **buf);
void	parse_triangle(t_scene *s, char **line, char **buf);

/*
****source - coord_n_rgb.c****
*/
t_vec3	parse_coord(t_scene *s, char **buf, int i, char **line);
t_rgb	parse_rgb(t_scene *s, char **buf, int i, char **line);
void	resize_resolution(t_scene *s);

/*
****source - filter_n_effect.c****
*/
int		check_filter(t_scene *s, char *buf);
int		check_rainbow(char *filter, char *buf);
int		check_checkerboard(char *effect, char *buf);
int		check_antialising(char *effect, char *buf);
void	render_with_antialiasing(t_scene *s, t_ray *r, double x,
		double y);

/*
****source - light_n_shadow.c****
*/
int		between_light_n_obj(t_vec3 light, t_vec3 point, t_vec3 origin);
int		is_obj_shaded(t_scene s, t_ray *r);
void	obj_disruption_for_shading(t_light *l, t_obj_clr *obj);
t_vec3	parse_parallel(t_scene *s, char **buf, int i, char **line);
int		check_parallel(char *s);

/*
****source - bmp.c****
*/
void	write_bmp_header(t_scene *s, int fd, int file_size);
void	write_bmp_image(t_scene *s, int fd);
void	save_bmp(t_scene s, int fd);

/*
****source - render.c****
*/
void	draw_obj_on_canvas(t_scene s, t_ray *r);
void	render_pixel(t_scene *s, t_ray *r, double x, double y);
void	render_scene(t_scene *s);

/*
****source - camera.c****
*/
t_vec3	get_local_camera_coord(t_scene *s, double pix_x, double pix_y);
void	make_camera_to_world_matrix(t_scene *s);
void	apply_rgb_filter(char c, t_rgb *color);
void	apply_rainbow_pattern(t_obj_clr *obj);
void	apply_checkerboard(t_obj_clr *obj);

/*
****source - color.c****
*/
t_rgb	get_mix_color(t_rgb c0, t_rgb c1);
t_rgb	get_spot_light(t_scene *s, t_obj_clr *obj, int i);
t_rgb	get_ambient_color(t_scene *s, t_obj_clr *obj);
t_rgb	apply_sepia_filter(t_rgb color);
int		obj_color_to_canvas(t_scene s, t_obj_clr obj);

/*
****source - vec3_utils.c****
*/
t_vec3	vec3_add_vec3(t_vec3 v0, t_vec3 v1);
t_vec3	vec3_subtraction(t_vec3 v0, t_vec3 v1);
t_vec3	vec3_multiply_vec3(t_vec3 v0, t_vec3 v1);
t_vec3	scalar_multiply_vec3(double k, t_vec3 v);
double	vec3_dot_product(t_vec3 v0, t_vec3 v1);

/*
****source - vec3_utils2.c****
*/
double	vec3_self_dot_sqrt(t_vec3 v);
t_vec3	vec3_cross_product(t_vec3 v0, t_vec3 v1);
void	normalize_vec3(t_vec3 *v);
t_vec3	matrix_multiply_vec3(t_matrix m, t_vec3 r);
int		is_vec3_void(t_vec3 v);

/*
****source - vec3_utils3.c****
*/
int		is_n_valid(t_vec3 v3);
t_vec3	get_axis(char c);
t_vec3	get_horizon_axis(t_scene *s);

/*
****source - shpere.c****
*/
int		is_ray_intersect_sphere(t_scene *s, t_ray *r, int i);
int		is_shadow_in_sphere(t_scene s, t_ray *r, int i);
void	draw_sphere_on_canvas(t_scene s, t_ray *r, int i);

/*
****source - plane.c****
*/
void	draw_plane_on_canvas(t_scene s, t_ray *r, int i);
int		get_intersection_of_plane(t_scene *s, t_ray *r, t_sub_plane *pl);
int		is_shadow_in_plane(t_scene s, t_ray *r, int i);
int		is_ray_intersect_plane(t_scene *s, t_ray *r, t_sub_plane *pl);

/*
****source - square.c****
*/
int		is_intersect_inside_square(t_scene s, t_sub_plane *pl, int i);
int		is_shadow_in_square(t_scene s, t_ray *r, int i);
void	draw_square_on_canvas(t_scene s, t_ray *r, int i);

/*
****source - triangle.c****
*/
int		is_intersect_inside_triangle(t_scene s, int i, t_sub_plane *pl);
int		is_ray_intersect_triagle(t_scene *s, t_ray *r, int i,
		t_sub_plane *pl);
int		is_shadow_in_triangle(t_scene s, t_ray *r, int i);
void	draw_triangle_on_canvas(t_scene s, t_ray *r, int i);
void	get_triangle_edges(t_triangle *t);

/*
****source - triangle2.c****
*/
double	get_p_parameter(t_triangle *trngl, t_vec3 p0);
double	get_q_parameter(t_triangle *trngl, t_vec3 p0);

/*
****source - cylinder.c****
*/
void	get_cylinder_surface(t_scene *s, t_ray *r, int i);
int		is_ray_intersect_cylinder(t_scene *s, t_ray *r, int i);
void	get_cylinder_color(t_scene s, t_ray *r, int i);
void	draw_cylinder_on_canvas(t_scene s, t_ray *r, int i);

/*
****source - cylinder2.c****
*/
int		is_shadow_in_cap(t_scene s, t_ray *shad_r, int i);
int		is_shadow_in_cylinder(t_scene s, t_ray *shad_r, int i);
t_vec3	get_nearest_cap(t_scene s, int i);
int		is_ray_intersect_cap(t_scene *s, t_ray *r, int i,
		t_sub_plane *pl);
void	draw_cylinder_cap(t_scene s, t_ray *r, int i);

#endif
