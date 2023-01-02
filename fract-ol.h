/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:50:13 by mparisse          #+#    #+#             */
/*   Updated: 2022/12/31 15:04:32 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "mlx_linux/mlx.h"
#include <unistd.h>
#include "libft/libft.h"
#include "libft/ft_printf.h"
#include <math.h>


#define NMAX 255.
#define SCALE 0.9
#define	SIZERE 1000
#define SIZEIM 1000
#define LEFT 65361
#define RIGHT 65363
#define UP 65362
#define DOWN 65364
#define MANDEL 1
#define JULIA 2
#define NEWTON 3

typedef struct s_plane
{
	long double	remin;
	long double	remax;
	long double	immin;
	long double	immax;
	long double	size_view;
	long double	size_view_y;
	long double	pixelsize;
	long double	xratio;
	long double	yratio;
} t_plane;

typedef struct s_vars {
    void    *mlx;
    void    *win;
	int		color;
	long double		size_win_x;
	long double		size_win_y;
	void	*data;
	int		fractal;
	t_plane	*plane;
}   t_vars;

typedef struct s_complex_n {
	long double	re;
	long double	im;
}	t_complex_n;

typedef struct s_point {
	long double x;
	long double y;
}	t_point;

typedef struct s_middle
{
	int		middle_x;
	int		middle_y;
}	t_middle;

typedef struct s_circle
{
	int		rayon;
	int		diametres;
}	t_circle;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	mandel(t_plane plane, t_vars vars);
void	mandel_calcul(t_vars vars, t_plane plane);
int     ft_close(t_vars *vars);
int     keyhook(int key_code, t_vars *init, t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// mlx_stuff 
int mouse_hook(int button, int x,int y, t_vars *vars);
t_plane	find_new_plane_in(t_plane plane);
t_plane	find_new_plane_out(t_plane plane);
void	init_plane_vars(t_plane *plane, t_vars *vars);

// Mandelbrot stuff 1
int		get_color(long double t);
int		is_mandel(t_complex_n c, t_vars vars);
long double	check(t_complex_n z);
void	init_img(t_data *img, t_vars *vars);
t_complex_n	function_mandel(t_complex_n arg1, t_complex_n arg2);

// Mandelbrot stuff 2
t_plane	plane_to_left(t_plane plane);
t_plane	plane_to_right(t_plane plane);
t_plane	plane_to_up(t_plane plane);
t_plane	plane_to_down(t_plane plane);

// print consigne
void	print_consigne();
