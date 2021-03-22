/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:06:10 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 20:13:27 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec3_self_dot_sqrt(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec3	vec3_cross_product(t_vec3 v0, t_vec3 v1)
{
	t_vec3 result;

	result.x = v0.y * v1.z - v0.z * v1.y;
	result.y = -1.0 * (v0.x * v1.z - v0.z * v1.x);
	result.z = v0.x * v1.y - v0.y * v1.x;
	return (result);
}

void	normalize_vec3(t_vec3 *v)
{
	double denominator;

	denominator = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	v->x = v->x / denominator;
	v->y = v->y / denominator;
	v->z = v->z / denominator;
}

t_vec3	matrix_multiply_vec3(t_matrix m, t_vec3 v)
{
	t_vec3 result;

	result.x = m.vx.x * v.x + m.vy.x * v.y + m.vz.x * v.z;
	result.y = m.vx.y * v.x + m.vy.y * v.y + m.vz.y * v.z;
	result.z = m.vx.z * v.x + m.vy.z * v.y + m.vz.z * v.z;
	return (result);
}

int		is_vec3_void(t_vec3 v)
{
	return (v.x == 0 && v.y == 0 && v.z == 0 ? 0 : 1);
}
