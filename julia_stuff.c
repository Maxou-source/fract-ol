/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:44:35 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/07 05:15:58 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_plane_vars_julia(t_plane *plane, t_vars *vars, char **av)
{
	plane->c_for_julia.re = ft_atold(av[2]);
	plane->c_for_julia.im = ft_atold(av[3]);
	plane->remin = -2.0;
	plane->remax = 2.0;
	plane->immin = -2.0;
	plane->immax = 2.0;
	plane->size_view = plane->remax - plane->remin;
	plane->size_view_y = plane->immax - plane->immin;
	plane->pixelsize = plane->size_view / 500;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit (EXIT_FAILURE);
	vars->size_win_x = 500.;
	vars->size_win_y = 500.;
	vars->win = mlx_new_window(vars->mlx, vars->size_win_x, vars->size_win_y,
			"Julia");
	if (!vars->win)
	{
		free(vars->mlx);
		exit(EXIT_FAILURE);
	}
	vars->color_shift = 1;
	vars->plane = plane;
}

void	julia_calcul(t_plane plane, t_vars vars)
{
	t_complex_n	z;
	int			i;
	int			j;
	int			rgb;
	int			n;

	j = 0;
	while (j < vars.size_win_y)
	{
		i = 0;
		while (i < vars.size_win_x)
		{
			z.re = plane.remin + i * plane.pixelsize;
			z.im = plane.immax - j * plane.pixelsize;
			n = function_julia(z, plane);
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

int	function_julia(t_complex_n z, t_plane plane)
{
	int			n;
	t_complex_n	c;

	c.re = plane.c_for_julia.re;
	c.im = plane.c_for_julia.im;
	n = 0;
	while (n < NMAX)
	{
		z = function(z, c);
		n++;
		if (check(z) >= 4)
			break ;
	}
	return (n);
}

/*
	Pour "render" les fractales de Julia je reutilise egalement les fonctions
	check et get_color utlise pour Mandelbrot 
	J'ai egalement utilise la fonction init_img, pour les deux.
*/