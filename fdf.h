#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <mlx.h>
#include "get_next_line.h"
#include "libft/libft.h"

typedef struct	s_fdf
{
	int		width;
	int		height;
	int		**map;
	int		zoom;
	int		color;
	float	angle;
	float	dim;

	void	*mlx_ptr;
	void	*win_ptr;
} 	t_fdf;

int		get_height(char *file);

int		ft_wdcounter(char const *str, char c);

int		get_width(char *file);

void	fill_map(int *map_line, char *line);

void	read_map(char *file, t_fdf *data);

void	draw(t_fdf *data);

void	bresehnam(float x0, float y0, float x1, float y1, t_fdf *data);

float	absolut(float i);
