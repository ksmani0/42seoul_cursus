/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:31:34 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 19:43:21 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		is_n_valid(t_vec3 v)
{
	if (v.x < -1 || v.x > 1)
		return (0);
	else if (v.y < -1 || v.y > 1)
		return (0);
	else if (v.z < -1 || v.z > 1)
		return (0);
	return (1);
}

t_vec3	get_axis(char c)
{
	t_vec3 result;

	result.x = 0;
	result.y = 0;
	result.z = 0;
	if (c == 'x')
		result.x = 1;
	else if (c == 'y')
		result.y = 1;
	else if (c == 'z')
		result.z = 1;
	return (result);
}

t_vec3	get_horizon_axis(t_scene *s)
{
	t_vec3 conversion_x;

	conversion_x.z = 0;
	if (s->camera[s->i_cam]->n.x == 0 && s->camera[s->i_cam]->n.y == 0)
	{
		conversion_x.y = 0;
		if (s->camera[s->i_cam]->n.z > 0)
			conversion_x.x = -1.0;
		else if (s->camera[s->i_cam]->n.z < 0)
			conversion_x.x = 1.0;
		else if (s->camera[s->i_cam]->n.z == 0)
			check_error_exit(s, 9);
	}
	else
	{
		conversion_x.x = s->camera[s->i_cam]->n.y;
		conversion_x.y = s->camera[s->i_cam]->n.x * -1.0;
	}
	return (conversion_x);
}
