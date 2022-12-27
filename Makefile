# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 10:32:25 by mparisse          #+#    #+#              #
#    Updated: 2022/12/25 15:08:06 by mparisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = fracts_p.c mlx_stuff.c mandelbrot_stuff.c \
mandelbrot_stuff_2.c print_consigne.c

OBJS = ${SRCS:.c=.o}

CC = gcc -O3

LIBS = libmlx_Linux.a libft.a -lm -lX11 -lXext  

all : $(NAME)

$(NAME) : ${OBJS}
	make -C mlx_linux/ clean
	make -C mlx_linux/ 
	mv mlx_linux/libmlx_Linux.a .
	make -C libft/ fclean
	make -C libft 
	mv libft/libft.a . 
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

norme :
	norminette $(SRCS)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)
	rm -rf libft.a libmlx_Linux.a

re : fclean $(NAME)

.PHONY : all clean fclean re
