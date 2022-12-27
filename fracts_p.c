/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracts_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:14:38 by mparisse          #+#    #+#             */
/*   Updated: 2022/12/23 15:14:39 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

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
			n = is_mandel(c, vars);
			if (n != NMAX)
			{
				rgb = get_color(n / NMAX);
				my_mlx_pixel_put(vars.data, i, j, rgb);
			}
			i++;
		}
		j++;
	}
}
//		(vars->plane->xratio) = x / vars->size_win_x;

void	init_plane_vars(t_plane *plane, t_vars *vars)
{
	plane->remin = -2.0;
	plane->remax = 2.0;
	plane->immin = -1.0;
	plane->immax = 1.0;
	plane->size_view = plane->remax - plane->remin;
	plane->size_view_y = plane->immax - plane->immin;
	plane->pixelsize = plane->size_view / 1000;
	vars->mlx = mlx_init();
	vars->size_win_x = 1000.;
	vars->size_win_y = 500.;
	vars->win = mlx_new_window(vars->mlx, vars->size_win_x, vars->size_win_y,
			"Mandelbrot");
	vars->plane = plane;
}

void	mandel(t_plane plane, t_vars vars)
{
	t_data		img;
	t_complex_n	c;

	init_img(&img, &vars);
	vars.data = &img;
	mandel_calcul(vars, plane);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_destroy_image(vars.mlx, img.img);
}

int	parsing(char *str)
{
	if (ft_strcmp(str, "Mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(str, "Julia") == 0)
		return (2);
	else if (ft_strcmp(str, "Sier") == 0)
		return (3);
	return (0);
}

void	julia()
{
	t_data	img;
	t_complex_n	c;

	
}

int	main(int ac, char **av)
{
	t_plane	plane;
	t_vars	vars;

	if (ac == 2)
	{
		if (parsing(av[1]) == 1)
		{
			init_plane_vars(&plane, &vars);
			mandel(plane, vars);
			mlx_key_hook(vars.win, &keyhook, &vars);
			mlx_hook(vars.win, 33, 1L << 17, ft_close, &vars);
			mlx_loop(vars.mlx);
		}
		else if (parsing(av[1]) == 2)
		{
			init_plane_vars(&plane, &vars);
			mlx_loop(vars.mlx);
		}
		else if (parsing(av[1]) == 3)
		{
			ft_printf("en cours de travaux");
		}
	}
	else
	{
		print_consigne();
		return (0);
	}
	return (0);
}

// Mandelbrot
// Julia
// triangle truc