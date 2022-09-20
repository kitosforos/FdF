# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maralons <maralons@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 21:09:00 by maralons          #+#    #+#              #
#    Updated: 2022/09/20 21:57:40 by maralons         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
# CFLAGS = -Wall -Wextra -Werror

NAME = fdf

SRCS = srcs/draw.c srcs/fdf.c srcs/get_next_line.c srcs/get_next_line_utils.c srcs/parse.c
OBJS = ${SRCS:.c=.o}
INC = -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(OBJS) -Llibft -lft -o $(NAME) -fsanitize=address -g3 -lmlx -framework OpenGL -framework AppKit -L.
	
srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	make clean -C libft
	rm -rf $(OBJS)

fclean:
	make fclean -C libft
	rm -rf $(OBJS) $(NAME)

re: fclean all