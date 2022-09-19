/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:48:32 by maralons          #+#    #+#             */
/*   Updated: 2022/09/19 15:51:34 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MAX(a, b) (a > b ? a : b)

float	absolut(float i)
{
	return ((i < 0) ? -i : i);
}

void	projection(float *x, float *y, int z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	bresehnam(float x0, float y0, float x1, float y1, t_fdf *data)
{
	float advance_x;
	float advance_y;
	int	max;
	int z0;
	int	z1;
	int	color;
	
	z0 = data->map[(int)y0][(int)x0];
	z1 = data->map[(int)y1][(int)x1];
	if (z0 || z1)
		data->color = 0x00890000;
	else
		data->color = 0x00FFE9A0;
	if (z0)
		z0*=data->dim;
	if (z1)
		z1*=data->dim;
	x0 *= data->zoom;
	x1 *= data->zoom;
	y0 *= data->zoom;
	y1 *= data->zoom;
	projection(&x0, &y0, z0, data->angle);
	projection(&x1, &y1, z1, data->angle);
	x0 += 300;
	x1 += 300;
	y0 += 300;
	y1 += 300;
	advance_x = x1 - x0;
	advance_y = y1 - y0;
	max = MAX(absolut(advance_x), absolut(advance_y));
	advance_x /= max;
	advance_y /= max;
	while ((int)(x0 - x1) || (int)(y0 - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, data->color);
		x0 += advance_x;
		y0 += advance_y;
	}
}

void	draw(t_fdf *data)
{
	int i;
	int	j;

	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			if (i < data->width - 1)
				bresehnam(i, j, i + 1, j, data);
			if (j < data->height - 1)
				bresehnam(i, j, i, j + 1, data);
			i++;
		}
		j++;
	}
}