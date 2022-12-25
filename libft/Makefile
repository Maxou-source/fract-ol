# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 17:21:41 by mparisse          #+#    #+#              #
#    Updated: 2022/12/23 15:25:17 by mparisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strcmp.c ft_utils.c ft_printf.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra 

${NAME}:	${OBJS}
		ar rc libft.a ${OBJS}

so:
	${CC} -nostartfiles -shared -o libft.so ${CFLAGS} ${SRCS}

norme:
	norminette ${SRCS}

all:	${NAME}

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf  ${NAME}

re:	fclean ${NAME}
