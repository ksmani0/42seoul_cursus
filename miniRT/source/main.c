/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungmki <seungmki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:06:10 by seungmki          #+#    #+#             */
/*   Updated: 2021/03/10 02:56:38 by seungmki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	g_now_obj = 0;

void	free_each_obj(t_scene *s, int i)
{
	while (i <= s->idx_rec[2])
		free(s->camera[i++]);
	i = 0;
	while (i <= s->idx_rec[3])
		free(s->light[i++]);
	i = 0;
	while (i <= s->idx_rec[4])
		free(s->sphere[i++]);
	i = 0;
	while (i <= s->idx_rec[5])
		free(s->plane[i++]);
	i = 0;
	while (i <= s->idx_rec[6])
		free(s->square[i++]);
	i = 0;
	while (i <= s->idx_rec[7])
		free(s->cylinder[i++]);
	i = 0;
	while (i <= s->idx_rec[8])
		free(s->triangle[i++]);
}

void	free_scene(t_scene *s)
{
	free(s->camera);
	free(s->light);
	free(s->sphere);
	free(s->plane);
	free(s->square);
	free(s->cylinder);
	free(s->triangle);
}

void	check_error_exit(t_scene *scene, int error)
{
	if (error == 1)
		printf("Error\n:wrong file entered!\n");
	else if (error == 2)
		printf("Error\n:the second argument is wrong!\n");
	else if (error == 3)
		printf("Error\n:while reaing 'minirt_guide.txt' file!\n");
	else if (error == 4)
		printf("Error\n:while reading '.rt' file!\n");
	else if (error == 5 || error == 9)
		printf("Error\n:the '.rt' file format is incorrect!\n");
	else if (error == 6)
		printf("Error\n:while allocating memory!\n");
	else if (error == 7)
		printf("Error\n:function in mlx.h has failed!\n");
	else if (error == 8)
		printf("Error\n:while openig bmp file!\n");
	if (error == 6 || error == 8 || error == 9)
	{
		free_each_obj(scene, 0);
		free_scene(scene);
	}
	exit(1);
}

void	guide_output(t_scene *scene)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open("minirt_guide.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	close(fd);
	if (ret == -1)
		check_error_exit(scene, 3);
}

int		main(int ac, char **av)
{
	t_scene	scene;
	char	*tmp;

	ft_bzero(&scene, sizeof(t_scene));
	if (ac == 2 || ac == 3)
	{
		if ((tmp = ft_strstr(av[1], ".rt")) == 0 || *(tmp + 3) != 0)
			check_error_exit(&scene, 1);
		if (ac == 3 && (ft_strcmp(av[2], "--save")) != 0)
			check_error_exit(&scene, 2);
		guide_output(&scene);
		scene.win.mlx_p = mlx_init();
		read_rt(av[1], &scene);
		if (scene.idx_rec[4] == 0 && scene.idx_rec[5] == 0 &&
		scene.idx_rec[6] == 0 && scene.idx_rec[7] == 0 &&
		scene.idx_rec[8] == 0)
			check_error_exit(&scene, 1);
		resize_resolution(&scene);
		ac == 3 ? save_bmp(scene, 0) : run_minirt(scene);
	}
	else
		printf("Error\n:no arguments entered!\n");
	return (0);
}
