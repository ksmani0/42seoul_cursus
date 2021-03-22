/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:06:10 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 19:06:14 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vec3_add_vec3(t_vec3 v0, t_vec3 v1)
{
	t_vec3 result;

	result.x = v0.x + v1.x;
	result.y = v0.y + v1.y;
	result.z = v0.z + v1.z;
	return (result);
}

t_vec3	vec3_subtraction(t_vec3 v0, t_vec3 v1)
{
	t_vec3 result;

	result.x = v0.x - v1.x;
	result.y = v0.y - v1.y;
	result.z = v0.z - v1.z;
	return (result);
}

t_vec3	vec3_mulitply_vec3(t_vec3 v0, t_vec3 v1)
{
	t_vec3 result;

	result.x = v0.x * v1.x;
	result.y = v0.y * v1.y;
	result.z = v0.z * v1.z;
	return (result);
}

t_vec3	scalar_multiply_vec3(double k, t_vec3 v)
{
	t_vec3 result;

	result.x = k * v.x;
	result.y = k * v.y;
	result.z = k * v.z;
	return (result);
}

double	vec3_dot_product(t_vec3 v0, t_vec3 v1)
{
	return (v0.x * v1.x + v0.y * v1.y + v0.z * v1.z);
}
