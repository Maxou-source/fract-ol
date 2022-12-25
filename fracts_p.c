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

void	mandel(t_plane plane, t_vars vars)
{
	// t_vars	vars;
	t_data	img;
	t_complex_n	c;
	int		i;
	int		j;
	int		n;
	int		rgb;
	static int	ok;

	init_mandel(&img, &vars);
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
				my_mlx_pixel_put(&img, i, j, rgb);
			}
			i++;
		}
		j++;
	}
	vars.data = &img;
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_mouse_get_pos(vars.mlx ,vars.win, &i, &j);
}

int	parsing(char *str)
{
	if (ft_strcmp(str, "Mandelbrot") == 0)
		return (1);
	if (ft_strcmp(str, "Julia") == 0)
		return (2);
	return (0);
}

int	main(int ac, char **av)
{
	t_plane plane;
	t_vars	vars;

	plane.remin = -2.0;
	plane.remax = 2.0;
	plane.immin = -1.0;
	plane.immax = 1.0;
	plane.size_view = plane.remax - plane.remin;
	plane.size_view_y = plane.immax - plane.immin;
	plane.pixelsize = plane.size_view / 1000;
	vars.mlx = mlx_init();
	vars.size_win_x = 1000.;
	vars.size_win_y = 500.;
	vars.win = mlx_new_window(vars.mlx, vars.size_win_x, vars.size_win_y,
			"Mandelbrot");
	vars.plane = &plane;
	if (ac != 2)
	{
		ft_printf("ok");
		return (0);
	}
	if (parsing(av[1]) == 1)
	{
		mandel(plane, vars);
		mlx_key_hook(vars.win, &keyhook, &vars, vars.data);
    	mlx_hook(vars.win, 33, 1L<<17, ft_close, &vars);
		mlx_loop(vars.mlx);
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