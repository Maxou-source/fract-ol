/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:43:58 by mparisse          #+#    #+#             */
/*   Updated: 2022/12/24 13:44:01 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	init_img(t_data *img, t_vars *vars)
{
	img->img = mlx_new_image(vars->mlx, vars->size_win_x, vars->size_win_y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length,
			&img->endian);
}
	// vars->data = img;
	// vars->mlx = mlx_init();
	// vars->size_win_x = 1000;
	// vars->size_win_y = 500;
	// vars->win = mlx_new_window(vars->mlx, vars->size_win_x, vars->size_win_y,
	// 		"Mandelbrot");

t_complex_n	function(t_complex_n arg1, t_complex_n arg2)
{
	t_complex_n	res;
	float		zr;
	float		zi;
	float		cr;
	float		ci;

	zr = arg1.re;
	zi = arg1.im;
	cr = arg2.re;
	ci = arg2.im;
	res.re = pow(zr, 2) - pow(zi, 2) + cr;
	res.im = 2 * zr * zi + ci;
	return (res);
}

float	check(t_complex_n z)
{
	float	a;
	float	b;

	a = pow(z.re, 2);
	b = pow(z.im, 2);
	a = a + b;
	return (a);
}

int	is_mandel(t_complex_n c, t_vars vars)
{
	t_complex_n	z;
	t_complex_n	zderiv;
	t_complex_n	tmp;
	int			n;

	zderiv.re = 0;
	zderiv.im = 0;
	tmp.re = 0;
	tmp.im = 0;
	z.re = 0;
	z.im = 0;
	n = 0;
	while (n < NMAX)
	{
		tmp = function(tmp, c);
		z = tmp;
		n++;
		if (check(z) >= 4)
			break ;
	}
	return (n);
}

int	get_color(float t)
{
	double	rgb[4];

	rgb[3] = 0;
	rgb[0] = 9.0 * (1 - t) * pow(t, 3) * 255.0;
	rgb[1] = 15.0 * pow((1 - t), 2) * pow(t, 2) * 255.0;
	rgb[2] = 8.5 * pow((1 - t), 3) * t * 255.0;
	return (rgb[0] * rgb[1] * rgb[2]);
}
	// float x = pow(zr, 2) - pow(zi, 2) + cr; 
	// float y = 2 * zr * zi + ci;
