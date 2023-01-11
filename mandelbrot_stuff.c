/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_stuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:43:58 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/08 01:47:52 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_plane_vars_mandel(t_plane *plane, t_vars *vars)
{
	plane->remin = -2.0;
	plane->remax = 2.0;
	plane->immin = -1.0;
	plane->immax = 1.0;
	plane->size_view = plane->remax - plane->remin;
	plane->size_view_y = plane->immax - plane->immin;
	plane->pixelsize = plane->size_view / 1000;
	plane->pixelsize_y = plane->size_view_y / 500;
	vars->fractal = MANDEL;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit (EXIT_FAILURE);
	vars->size_win_x = 1000.;
	vars->size_win_y = 500.;
	vars->win = mlx_new_window(vars->mlx, vars->size_win_x, vars->size_win_y,
			"Mandelbrot");
	if (!vars->win)
	{
		free(vars->mlx);
		exit(EXIT_FAILURE);
	}
	vars->plane = plane;
	vars->color_shift = 1;
}

void	init_img(t_data *img, t_vars *vars)
{
	img->img = mlx_new_image(vars->mlx, vars->size_win_x, vars->size_win_y);
	if (!img->img)
	{
		free(img->img);
		free_mlx(vars);
		exit(EXIT_FAILURE);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length,
			&img->endian);
	if (!img->addr)
	{
		free(img->img);
		free(img->addr);
		free_mlx(vars);
		exit(EXIT_FAILURE);
	}
}

void	mandel_calcul(t_vars vars, t_plane plane)
{
	int			i;
	int			j;
	int			n;
	int			rgb;
	t_complex_n	c;

	i = 0;
	j = 0;
	while (j < vars.size_win_y)
	{
		i = 0;
		while (i < vars.size_win_x)
		{
			c.re = plane.remin + i * plane.pixelsize;
			c.im = plane.immax - j * plane.pixelsize;
			n = is_mandel(c);
			if (n != NMAX)
			{
				rgb = get_color(n / NMAX, vars.color_shift);
				my_mlx_pixel_put(&vars.data, i, j, rgb);
			}
			i++;
		}
		j++;
	}
}

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
