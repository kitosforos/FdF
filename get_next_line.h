/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maralons <maralons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:56:38 by maralons          #+#    #+#             */
/*   Updated: 2022/09/18 18:24:45 by maralons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char			*get_next_line(int fd);

char			*readbuff(char	*aux, int fd);

char			*get_line(char *aux);

char			*get_aux(char *aux);

unsigned long	ft_strlen(const char *s);

char			*ft_strjoin(char *s1, char *s2);

char			*ft_strchr(char *s, int c);
#endif