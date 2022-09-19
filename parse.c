/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:41:38 by maralons          #+#    #+#             */
/*   Updated: 2022/09/18 18:47:35 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int		ft_wdcounter(char const *str, char c)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

int	get_width(char *file)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	width = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_map(int *map_line, char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	while (nums[i])
	{
		map_line[i] = ft_atoi(nums[i]);
		i++;
	}
	i = 0;
	while(nums[i])
	{
		free(nums[i++]);
	}
	free(nums);
}

void	read_map(char *file, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	data->height = get_height(file);
	data->width = get_width(file);
	data->map = (int **)malloc(sizeof(int*) * data->height + 1);
	while (i < data->height)
		data->map[i++] = malloc(sizeof(int) * data->width + 1);
	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_map(data->map[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
}