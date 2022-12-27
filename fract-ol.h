/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:50:13 by mparisse          #+#    #+#             */
/*   Updated: 2022/12/23 02:21:01 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "mlx_linux/mlx.h"
#include <unistd.h>
#include "libft/libft.h"
#include "libft/ft_printf.h"


#define NMAX 255.
#define SCALE 0.9
#define	SIZERE 1000
#define SIZEIM 1000

typedef struct s_plane
{
	float	remin;
	float	remax;
	float	immin;
	float	immax;
	float	size_view;
	float	size_view_y;
	float	pixelsize;
	float	xratio;
	float	yratio;
} t_plane;

typedef struct s_vars {
    void    *mlx;
    void    *win;
	float		size_win_x;
	float		size_win_y;
	void	*data;
	t_plane	*plane;
}   t_vars;

typedef struct s_complex_n {
	float	re;
	float	im;
}	t_complex_n;

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
int     ft_close(t_vars *vars);
int     keyhook(int key_code, t_vars *init, t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// Mandelbrot stuff 1
int		get_color(float t);
int		is_mandel(t_complex_n c, t_vars vars);
float	check(t_complex_n z);
void	init_img(t_data *img, t_vars *vars);
t_complex_n	function_mandel(t_complex_n arg1, t_complex_n arg2);

// Mandelbrot stuff 2
t_plane	decrement_plane(t_plane plane);
t_plane	increment_plane(t_plane plane);
t_plane	plane_to_left(t_plane plane);
t_plane	plane_to_right(t_plane plane);
t_plane	plane_to_up(t_plane plane);
t_plane	plane_to_down(t_plane plane);

// print consigne
void	print_consigne();
