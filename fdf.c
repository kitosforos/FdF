/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:30:39 by maralons          #+#    #+#             */
/*   Updated: 2022/09/19 15:40:03 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int key, t_fdf *fdf)
{
	printf("%d\n", key);
	if (key == 53)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		free(fdf->map);
		exit(0);
	}
	else if (key == 13)
	{
		fdf->angle += 0.05;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	else if (key == 12)
	{
		fdf->angle -= 0.05;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	else if (key == 4)
	{
		fdf->dim += 0.5;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	else if (key == 37)
	{
		fdf->dim -= 0.5;
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	}
	draw(fdf);
	return (0);
}

int	main(int argc,	char *argv[])
{
	t_fdf	*data;
	int	i;
	int	j;
	
	
	i = 0;
	data = (t_fdf*)malloc(sizeof(t_fdf));
	read_map(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FdF");
	data->zoom = 20;
	data->angle = 0.8;
	data->dim = 1;
	draw(data);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_loop(data->mlx_ptr);
}
