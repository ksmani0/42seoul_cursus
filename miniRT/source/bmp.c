/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:06:10 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/09 19:48:44 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	write_bmp_header(t_scene *s, int fd, int file_size)
{
	t_uchar	bmp_h[54];
	int		minus_y;

	ft_bzero(bmp_h, 54);
	file_size = 4 * s->y * s->x + 54;
	minus_y = -1 * s->y;
	bmp_h[0] = 'B';
	bmp_h[1] = 'M';
	bmp_h[2] = (t_uchar)file_size;
	bmp_h[3] = (t_uchar)(file_size >> 8);
	bmp_h[4] = (t_uchar)(file_size >> 16);
	bmp_h[5] = (t_uchar)(file_size >> 24);
	bmp_h[10] = 54;
	bmp_h[14] = 40;
	bmp_h[18] = (t_uchar)s->x;
	bmp_h[19] = (t_uchar)(s->x >> 8);
	bmp_h[20] = (t_uchar)(s->x >> 16);
	bmp_h[21] = (t_uchar)(s->x >> 24);
	bmp_h[22] = (t_uchar)minus_y;
	bmp_h[23] = (t_uchar)(minus_y >> 8);
	bmp_h[24] = (t_uchar)(minus_y >> 16);
	bmp_h[25] = (t_uchar)(minus_y >> 24);
	bmp_h[26] = 1;
	bmp_h[28] = 32;
	write(fd, bmp_h, 54);
}

void	write_bmp_image(t_scene *s, int fd)
{
	int i;

	i = 0;
	while (i < (s->img.len / 4) * s->y)
	{
		if (i % (s->img.len / 4) < s->x)
			write(fd, &s->img.addr[i * 4], 4);
		++i;
	}
}

void	save_bmp(t_scene s, int fd)
{
	if (!(s.img.inst = mlx_new_image(s.win.mlx_p, s.x, s.y)))
		check_error_exit(&s, 7);
	if (!(s.img.addr = mlx_get_data_addr(s.img.inst,
	&s.img.b_pix, &s.img.len, &s.img.end)))
		check_error_exit(&s, 7);
	if ((fd = open("output_bmp/result.bmp", O_CREAT | O_WRONLY | O_TRUNC,
		0744)) == -1)
		check_error_exit(&s, 8);
	s.i_cam = s.idx_rec[2] - 1;
	render_scene(&s);
	printf("Image saving starts!\n");
	write_bmp_header(&s, fd, 0);
	write_bmp_image(&s, fd);
	close(fd);
	free_each_obj(&s, 0);
	free_scene(&s);
	printf("Image saving is complete! Check the output_bmp folder:)\n");
}
