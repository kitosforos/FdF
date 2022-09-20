/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:48:32 by maralons          #+#    #+#             */
/*   Updated: 2022/09/20 22:05:55 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	greater(float x, float y)
{
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (x > y)
		return (x);
	else
		return (y);
}

void	projection(float *x, float *y, int z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	bresehnam(t_point *p0, t_point *p1, t_fdf *data)
{
	float advance_x;
	float advance_y;
	int	max;
	
	p0->z = data->map[(int)p0->y][(int)p0->x];
	p1->z = data->map[(int)p1->y][(int)p1->x];
	if (p0->z || p1->z)
		data->color = 0x00890000;
	else
		data->color = 0x00FFE9A0;
	if (p0->z)
		p0->z*=data->dim;
	if (p1->z)
		p1->z*=data->dim;
	p0->x *= data->zoom;
	p1->x *= data->zoom;
	p0->y *= data->zoom;
	p1->y *= data->zoom;
	projection(&p0->x, &p0->y, p0->z, data->angle);
	projection(&p1->x, &p1->y, p1->z, data->angle);
	p0->x += data->shiftx;
	p1->x += data->shiftx;
	p0->y += data->shifty;
	p1->y += data->shifty;
	advance_x = p1->x - p0->x;
	advance_y = p1->y - p0->y;
	max = greater(advance_x, advance_y);
	advance_x /= max;
	advance_y /= max;
	while ((int)(p0->x - p1->x) || (int)(p0->y - p1->y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, p0->x, p0->y, data->color);
		p0->x += advance_x;
		p0->y += advance_y;
	}
}

void	draw(t_fdf *data)
{
	t_point *p0 = NULL;
	t_point *p1 = NULL;

	// p0 = NULL;
	// p1 = NULL;
	p0->y = 0;
	p1->y = 1;
	while (p0->y < data->height)
	{
		p0->x = 0;
		p1->x = 1;
		while (p0->x < data->width)
		{
			if (p0->x < data->width - 1)
			{
				p1->y--;
				bresehnam(p0, p1, data);
				p1->y++;
			}
			if (p0->y < data->height - 1)
			{
				p1->x--;
				bresehnam(p0, p1, data);
				p1->x++;
			}
			p0->x++;
			p1->x++;
		}
		p0->y++;
		p1->y++;
	}
}
