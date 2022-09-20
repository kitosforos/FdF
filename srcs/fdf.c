/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:30:39 by maralons          #+#    #+#             */
/*   Updated: 2022/09/20 21:35:38 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int key, t_fdf *fdf)
{
	if (key == 13)
		fdf->angle += 0.05;
	else if (key == 12)
		fdf->angle -= 0.05;
	else if (key == 4)
		fdf->dim += 0.5;
	else if (key == 37)
		fdf->dim -= 0.5;
	else if (key == 6)
		fdf->zoom += 2;
	else if (key == 7)
		fdf->zoom -= 2;
	else if (key == 126)
		fdf->shifty -= 9;
	else if (key == 125)
		fdf->shifty += 9;
	else if (key == 123)
		fdf->shiftx -= 9;
	else if (key == 124)
		fdf->shiftx += 9;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw(fdf);
	return (0);
}

int	key_hook2(int key, t_fdf *fdf)
{
	int	i;

	i = 0;
	if (key == 53)
	{
		while (i < fdf->height)
			free(fdf->map[i++]);
		free(fdf->map);
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		free(fdf);
		exit(0);
	}
	return (0);
}

int	main(int argc,	char *argv[])
{
	t_fdf	*data;
	int		i;

	if (argc != 2)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	i = 0;
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_map(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "FdF");
	data->zoom = 20;
	data->angle = 0.8;
	data->dim = 1;
	data->shiftx = 800;
	data->shifty = 400;
	draw(data);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_key_hook(data->win_ptr, key_hook2, data);
	mlx_loop(data->mlx_ptr);
}
