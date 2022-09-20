/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:57:27 by maralons          #+#    #+#             */
/*   Updated: 2022/04/30 13:52:49 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readbuff(char	*aux, int fd)
{
	char	*buff;
	size_t	readed;
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	readed = 1;
	while (readed && !ft_strchr(aux, '\n'))
	{
		buff = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
			return (0);
		readed = read(fd, buff, BUFFER_SIZE);
		if ((int)readed == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readed] = 0;
		aux = ft_strjoin(aux, buff);
		free(buff);
	}
	return (aux);
}

char	*get_line(char *aux)
{
	int		i;
	char	*dest;

	if (!aux)
		return (NULL);
	dest = malloc(sizeof(char) * ft_strlen(aux) + 2);
	if (!dest)
		return (0);
	i = 0;
	while (aux[i] != '\n' && aux[i])
	{
		dest[i] = aux[i];
		i++;
	}
	if (aux[i] == '\n')
		dest[i++] = '\n';
	else if (i == 0)
	{
		free(dest);
		return (NULL);
	}
	dest[i] = 0;
	return (dest);
}

char	*get_aux(char *aux)
{
	char	*dest;
	int		i;
	int		j;

	j = 0;
	dest = malloc (sizeof(char) * ft_strlen(aux) + 1);
	if (!dest)
		return (0);
	i = 0;
	while (aux[i] && aux[i] != '\n')
		i++;
	if (aux[i] == '\n')
		i++;
	else
	{
		free(aux);
		free(dest);
		return (NULL);
	}
	while (aux[i])
		dest[j++] = aux[i++];
	dest[j] = 0;
	free(aux);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*aux;
	char		*line;
	int			flag;

	flag = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	aux = readbuff(aux, fd);
	if (!aux)
		return (NULL);
	line = get_line(aux);
	if (!line)
	{
		free(aux);
		free(line);
		aux = NULL;
		return (NULL);
	}
	aux = get_aux(aux);
	return (line);
}

// int main(int argc, char **argv)
// {
// 	int fd = open(argv[1], O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// }
