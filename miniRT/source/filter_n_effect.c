/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_n_effect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:06:10 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 19:37:19 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_filter(t_scene *s, char *buf)
{
	if (buf == 0)
		return (1);
	else if (ft_strncmp(buf, "sepia", 5) == 0)
	{
		s->filter = 's';
		return (1);
	}
	else if (ft_strncmp(buf, "red", 3) == 0)
	{
		s->filter = 'r';
		return (1);
	}
	else if (ft_strncmp(buf, "green", 5) == 0)
	{
		s->filter = 'g';
		return (1);
	}
	else if (ft_strncmp(buf, "blue", 4) == 0)
	{
		s->filter = 'b';
		return (1);
	}
	return (0);
}

int		check_rainbow(char *filter, char *buf)
{
	if (buf == 0)
	{
		*filter = 0;
		return (1);
	}
	else if (ft_strncmp(buf, "rainbow", 7) == 0)
	{
		*filter = 'r';
		return (1);
	}
	return (0);
}

int		check_checkerboard(char *effect, char *buf)
{
	if (buf == 0)
	{
		*effect = 0;
		return (1);
	}
	else if (ft_strncmp(buf, "checker", 7) == 0)
	{
		*effect = 'k';
		return (1);
	}
	return (0);
}

int		check_antialising(char *effect, char *buf)
{
	if (buf == 0)
	{
		*effect = 0;
		return (1);
	}
	else if ((ft_strncmp(buf, "anti", 4)) == 0)
	{
		*effect = 'a';
		return (1);
	}
	return (0);
}

void	render_with_antialiasing(t_scene *s, t_ray *r, double x, double y)
{
	int		i;
	int		j;
	t_rgb	color;

	i = -1;
	color = (t_rgb){0, 0, 0};
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		{
			render_pixel(s, r, x + (j + 0.5) / 2, y + (i + 0.5) / 2);
			color.r += (r->color & 0x00ff0000) >> 16;
			color.g += (r->color & 0x0000ff00) >> 8;
			color.b += (r->color & 0x000000ff);
		}
	}
	r->color = ((int)(color.r / 4) << 16) + ((int)(color.g / 4) << 8)
		+ (int)(color.b / 4);
}
