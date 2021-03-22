/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:06:10 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 20:10:46 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	get_mix_color(t_rgb c0, t_rgb c1)
{
	t_rgb clr;

	clr.r = c0.r + c1.r > 255 ? 255 : c0.r + c1.r;
	clr.g = c0.g + c1.g > 255 ? 255 : c0.g + c1.g;
	clr.b = c0.b + c1.b > 255 ? 255 : c0.b + c1.b;
	return (clr);
}

t_rgb	get_spot_light(t_scene *s, t_obj_clr *obj, int i)
{
	t_rgb	clr;
	double	diffuse;
	double	specular;
	double	kd;

	i = 0;
	diffuse = vec3_dot_product(obj->light, obj->normal);
	kd = diffuse < 0 ? 0 : s->light[i]->inten;
	specular = pow(fmax(diffuse, 0.0), 50);
	clr.r = kd * s->light[i]->rgb.r * (obj->rgb.r * diffuse / 255 + specular);
	clr.g = kd * s->light[i]->rgb.b * (obj->rgb.g * diffuse / 255 + specular);
	clr.b = kd * s->light[i]->rgb.g * (obj->rgb.b * diffuse / 255 + specular);
	return (clr);
}

t_rgb	get_ambient_color(t_scene *s, t_obj_clr *obj)
{
	t_rgb color;

	color.r = s->ambient.inten * s->ambient.rgb.r * obj->rgb.r / 255;
	color.g = s->ambient.inten * s->ambient.rgb.g * obj->rgb.g / 255;
	color.b = s->ambient.inten * s->ambient.rgb.b * obj->rgb.b / 255;
	return (color);
}

t_rgb	apply_sepia_filter(t_rgb color)
{
	t_rgb result;

	result.r = color.r * 0.393 + color.g * 0.769 + color.b * 0.189;
	result.g = color.r * 0.349 + color.g * 0.686 + color.b * 0.168;
	result.b = color.r * 0.272 + color.g * 0.534 + color.b * 0.131;
	result.r = result.r > 255 ? 255 : result.r;
	result.g = result.g > 255 ? 255 : result.g;
	result.b = result.b > 255 ? 255 : result.b;
	return (result);
}

int		obj_color_to_canvas(t_scene s, t_obj_clr obj)
{
	t_rgb color;
	t_rgb sub_color;
	t_ray shadow;

	color = (t_rgb){ 0, 0, 0 };
	s.i_light = -1;
	while (s.light[++s.i_light] != 0)
	{
		normalize_vec3(&obj.normal);
		obj_disruption_for_shading(s.light[s.i_light], &obj);
		shadow.global = obj.light;
		shadow.origin = obj.p;
		sub_color = get_ambient_color(&s, &obj);
		if (is_obj_shaded(s, &shadow) == 0)
			sub_color = get_mix_color(sub_color,
						get_spot_light(&s, &obj, s.i_light));
		color = get_mix_color(color, sub_color);
	}
	if (s.light[0] == 0)
		color = get_ambient_color(&s, &obj);
	if (s.filter == 's')
		color = apply_sepia_filter(color);
	else if (s.filter == 'r' || s.filter == 'g' || s.filter == 'b')
		apply_rgb_filter(s.filter, &color);
	return (((int)color.r << 16) + ((int)color.g << 8) + (int)color.b);
}
