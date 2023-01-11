/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:50:13 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/10 00:17:07 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "mlx_linux/mlx.h"
# include <unistd.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <math.h> 

# define NMAX 100.
# define SCALE 0.9
# define SIZERE 1000
# define SIZEIM 1000
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define ZOOMIN 4
# define ZOOMOUT 5
# define MANDEL 1
# define JULIA 2
# define NEWTON 3
# define COLOR1 49
# define COLOR2 50
# define COLOR3 51

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_complex_n {
	float	re;
	float	im;
}	t_complex_n;

typedef struct s_roots {
	t_complex_n	r2;
	t_complex_n	r1;
	t_complex_n	r3;
}				t_roots;

typedef struct s_plane
{
	float		remin;
	float		remax;
	float		immin;
	float		immax;
	float		size_view;
	float		size_view_y;
	float		pixelsize;
	float		pixelsize_y;
	float		xratio;
	float		yratio;
	t_complex_n	c_for_julia;
}	t_plane;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		color;
	float	size_win_x;
	float	size_win_y;
	t_data	data;
	int		fractal;
	t_plane	*plane;
	int		posx;
	int		posy;
	t_roots	roots;
	int		color_shift;
}		t_vars;

typedef struct s_point {
	float	x;
	float	y;
}	t_point;

typedef void	(*t_func)(t_plane plane, t_vars vars);

// fracts_p
void		mandel(t_plane plane, t_vars vars);
void		julia(t_plane plane, t_vars vars);
void		newton(t_plane plane, t_vars vars);

//Mandelbrot stuff
void		init_plane_vars_mandel(t_plane *plane, t_vars *vars);
void		init_img(t_data *img, t_vars *vars);
void		mandel_calcul(t_vars vars, t_plane plane);
t_complex_n	function(t_complex_n arg1, t_complex_n arg2);
float		check(t_complex_n z);

// Mandelbrot stuff 2
float		is_mandel(t_complex_n c);
int			get_color(float t, int color_shift);

// Julia stuff
void		init_plane_vars_julia(t_plane *plane, t_vars *vars, char **av);
void		julia_calcul(t_plane plane, t_vars vars);
int			function_julia(t_complex_n z, t_plane plane);

// Newton stuff
void		init_plane_vars_newton(t_vars *vars, t_plane *plane);
void		newton_calcul(t_plane plane, t_vars vars);
// t_complex_n	function_newton(t_complex_n z, t_vars vars);

//complex functions
t_complex_n	divide_complex(t_complex_n arg1, t_complex_n arg2);
t_complex_n	multiply_complex(t_complex_n arg1);
t_complex_n	complex_by(t_complex_n z, float x);
t_complex_n	cubed_complex(t_complex_n z);
t_complex_n	function_minus(t_complex_n z);

// complex functions
t_complex_n	derivative(t_complex_n z);
int			plus_minus(t_complex_n z, t_complex_n res);

// mlx_stuff 
int			mouse_hook(int button, int x, int y, t_vars *vars);
int			keyhook(int key_code, t_vars *init);

// mlx_stuff_2
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			ft_close(t_vars *vars);
t_vars		change_color(t_vars *vars, int color);

// mouse movements 
t_plane		find_new_plane_out(t_vars *vars, t_plane *plane);
t_plane		find_new_plane_in(t_vars *vars, t_plane *plane);

// key movements
t_plane		plane_to_left(t_vars *vars);
t_plane		plane_to_right(t_vars *vars);
t_plane		plane_to_up(t_vars *vars);
t_plane		plane_to_down(t_vars *vars);

// print consigne
int			print_consigne(void);
int			parsing(char *str);
int			parsing_av(char **av);
void		free_mlx(t_vars *vars);

#endif