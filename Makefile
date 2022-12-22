# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 10:32:25 by mparisse          #+#    #+#              #
#    Updated: 2022/12/18 10:32:28 by mparisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = fracts.c  mlx_stuff.c

OBJS = ${SRCS:.c=.o}

CC = gcc

LIBS = libmlx_Linux.a -lm -lX11 -lXext  

all : $(NAME)

$(NAME) : ${OBJS}
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
