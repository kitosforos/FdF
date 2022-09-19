/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:48:42 by maralons          #+#    #+#             */
/*   Updated: 2022/09/18 18:35:06 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int		i;
	int		j;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	while (str[i] != 0)
		i++;
	j = 0;
	while (j <= i)
	{
		if (*str == (char)c)
			return (str);
		str++;
		j++;
	}
	return (NULL);
}

unsigned long	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (s2 == NULL || s1 == NULL)
		return (NULL);
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s == NULL)
		return (NULL);
	while (s1[i] != 0)
		s[j++] = s1[i++];
	i = 0;
	while (s2[i] != 0)
		s[j++] = s2[i++];
	s[j] = 0;
	free(s1);
	return (s);
}
