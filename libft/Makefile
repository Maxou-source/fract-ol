# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 17:21:41 by mparisse          #+#    #+#              #
#    Updated: 2023/01/09 23:13:45 by mparisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strcmp.c ft_utils.c ft_printf.c ft_atold.c ft_isdigit.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra 

${NAME}:	${OBJS}
		@ar rc libft.a ${OBJS}
		
.c.o :
	@gcc -Wall -Werror -Wall -c $< -o ${<:.c=.o}

norme:
	norminette ${SRCS}

all:	${NAME}

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf  ${NAME}

re:	fclean ${NAME}
