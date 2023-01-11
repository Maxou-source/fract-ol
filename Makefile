# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 10:32:25 by mparisse          #+#    #+#              #
#    Updated: 2023/01/09 23:38:04 by mparisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = fracts_p.c mlx_stuff.c mlx_stuff_2.c mandelbrot_stuff.c \
key_movements.c mouse_movements.c print_consigne_parsing.c \
mandelbrot_stuff_2.c julia_stuff.c complex_functions.c complex_functions_2.c \
newton_stuff.c


OBJS = ${SRCS:.c=.o}

CC = gcc -O3

CFLAGS = -Wall -Werror -Wextra

LIBS = libmlx_Linux.a libft.a -lm -lX11 -lXext  

all : $(NAME)

YELLOW = \033[0;93m

$(NAME) : ${OBJS}
	@echo "$(YELLOW)Compiling mlx"
	@make --no-print-directory -C mlx_linux/ 
	@echo "Compiling libft"
	@cp mlx_linux/libmlx_Linux.a .
	@make --no-print-directory -C libft 
	@cp libft/libft.a . 
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "Bien joue!"

.c.o :
	@gcc -Wall -Werror -Wall -c $< -o ${<:.c=.o}

norme :
	norminette $(SRCS) fractol.h libft

clean : 
	make -C libft/ clean
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)
	rm -rf libmlx_Linux.a libft.a

re : fclean $(NAME)

.PHONY : all clean fclean re libft mlx_linux
#.SILENT : all clean fclean re $(OBJS)
