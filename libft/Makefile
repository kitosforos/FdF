# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maralons <maralons@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 14:06:26 by maralons          #+#    #+#              #
#    Updated: 2022/09/18 18:32:50 by maralons         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memcmp.c  ft_memset.c  ft_strlcat.c ft_strncmp.c ft_tolower.c ft_bzero.c   ft_isalpha.c ft_isprint.c ft_memcpy.c  ft_strlcpy.c ft_strnstr.c ft_toupper.c ft_calloc.c  ft_isascii.c ft_memchr.c  ft_memmove.c ft_strdup.c  ft_strlen.c  ft_strrchr.c ft_substr.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BSRCS = ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ${SRCS}

OBJS = ${SRCS:.c=.o}

BOBJS = ${BSRCS:.c=.o}

S_NAME = .simple

B_NAME = .bonus

${NAME}: ${S_NAME}

${S_NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	rm -rf ${B_NAME}
	touch ${S_NAME}
	@echo "-------> Libft created"

all: ${NAME}

clean:
	rm -rf ${OBJS} ${BOBJS}
	@echo "---------> Objects cleaned"

fclean:
	rm -rf ${NAME} ${OBJS} ${BOBJS}
	@echo "--------> Everything cleaned"

re: clean all

bonus: ${B_NAME}

${B_NAME}: ${BOBJS}
	ar rc ${NAME} ${BOBJS}
	rm -rf ${S_NAME}
	touch ${B_NAME}
	@echo "-------> Bonus created"