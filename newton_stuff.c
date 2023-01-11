/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 03:10:11 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/10 00:17:53 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_roots(t_vars *vars)
{
	vars->roots.r2.re = -0.5;
	vars->roots.r2.im = 0.866;
	vars->roots.r3.re = -0.5;
	vars->roots.r3.im = -0.866;
	vars->roots.r1.re = 1.;
	vars->roots.r1.im = 0.;
	vars->color_shift = 1;
}

void	init_plane_vars_newton(t_vars *vars, t_plane *plane)
{
	vars->fractal = NEWTON;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit (EXIT_FAILURE);
	vars->size_win_x = 630.;
	vars->size_win_y = 870.;
	plane->remin = -1.44;
	plane->remax = 1.44;
	plane->immin = -2.5;
	plane->immax = 2.5;
	plane->size_view = plane->remax - plane->remin;
	plane->size_view_y = plane->immax - plane->immin;
	plane->pixelsize = plane->size_view / vars->size_win_x;
	plane->pixelsize_y = plane->size_view_y / vars->size_win_y;
	vars->win = mlx_new_window(vars->mlx, vars->size_win_x, vars->size_win_y,
			"Newton");
	if (!vars->win)
	{
		free(vars->mlx);
		exit(EXIT_FAILURE);
	}
	vars->plane = plane;
	init_roots(vars);
}

void	get_color_newton(int color, int (*res)[3])
{
	if (color == 1)
	{
		(*res)[0] = 0xA56ABD;
		(*res)[1] = 0xF9E79F;
		(*res)[2] = 0x1167B1;
	}
	if (color == 2)
	{
		(*res)[0] = 0x0061A4;
		(*res)[1] = 0xDDE9EF;
		(*res)[2] = 0xD60920;
	}
}

int	function_newton(t_complex_n z, t_vars vars, int *co, int *rgb)
{
	int			n;
	t_complex_n	keep;

	n = 0;
	while (n < 20)
	{
		keep = z;
		z = divide_complex(function_minus(z), derivative(z));
		z.re = keep.re - z.re;
		z.im = keep.im - z.im;
		if (plus_minus(z, vars.roots.r2) == 1)
			return (my_mlx_pixel_put(& vars.data, co[0], co[1], rgb[0]), 0);
		else if (plus_minus(z, vars.roots.r3) == 1)
			return (my_mlx_pixel_put(& vars.data, co[0], co[1], rgb[1]), 0);
		else if (plus_minus(z, vars.roots.r1) == 1)
			return (my_mlx_pixel_put(& vars.data, co[0], co[1], rgb[2]), 0);
		n++;
	}
	return (0);
}

void	newton_calcul(t_plane plane, t_vars vars)
{
	int			rgb[3];
	int			i;
	int			j;
	int			co[2];
	t_complex_n	z;

	j = 0;
	get_color_newton(vars.color_shift, & rgb);
	while (j < vars.size_win_y)
	{
		i = 0;
		while (i < vars.size_win_x)
		{
			z.re = plane.remin + i * plane.pixelsize;
			z.im = plane.immax - j * plane.pixelsize_y;
			co[0] = i;
			co[1] = j;
			function_newton(z, vars, co, rgb);
			i++;
		}
		j++;
	}
}

	// res1.re = 1.;
	// res1.im = 0.;

	// res2.re = -0.5;
	// res2.im = 1.732/2;

	// res3.re = -0.5;
	// res3.im = -1.732/2;