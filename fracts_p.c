/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracts_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:14:38 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/02 21:33:16 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

//		(vars->plane->xratio) = x / vars->size_win_x;

void	mandel(t_plane plane, t_vars vars)
{
	t_data		img;
	// t_complex_n	c;		

	if (vars.fractal != MANDEL)
	{
		ft_printf("y'a un souci");
		return ;
	}
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
	else if (ft_strcmp(str, "Newton") == 0)
		return (3);
	return (0);
}

// 1 -> Mandelbrot
// 2 -> Julia
// 3 -> SIer
// void	plane_to_win(t_point *c, t_plane plane)
// {
// 	(void) plane;
// 	printf("value : %9.6Lf", c->x);
// 	c->x = fabs(c->x - plane.size_view) / 0.008;//+ plane.remin;
// 	printf("apres x : %9.6Lf \n", c->x);
	
// 	printf("debut y : %9.6Lf \n", c->y);
// 	c->y = c->y * -1;
// 	printf("apres y : %9.6Lf \n", c->y);
// 	// printf("%9.6Lf", c.y);
// 	// return (c);
// }
// f(z) = z3 - 1

t_complex_n	divide_complex(t_complex_n arg1, t_complex_n arg2)
{
	t_complex_n	res;
	long double	a;
	long double	b;
	long double	c;
	long double	d;

	a = arg2.re;
	b = arg2.im;
	c = arg1.re;
	d = arg1.im;
	res.re = ((c * a ) + (b * d)) / (pow(a, 2) + pow(b, 2));
	res.im = ((a * d) - (c * b)) / (pow(a, 2) + pow(b, 2));
	printf("res : %Lf + %Lfi", res.re, res.im);
	return (res);
}

t_complex_n	multiply_complex(t_complex_n arg1, t_complex_n arg2)
{
	t_complex_n	res;
	long double	a;
	long double	b;
	long double	c;
	long double	d;

	a = arg1.re;
	b = arg1.im;
	c = arg2.re;
	d = arg2.im;
	res.re = (a * c) - (b * d);
	res.im = (a * d) + (b * c);
	printf("res : %Lf + %Lfi", res.re, res.im);
	return (res);
}

t_complex_n complex_by(t_complex_n z,long double x)
{
	z.re = z.re * x;
	z.im = z.im * x;
	return(z);
}

void newton(t_vars *vars, t_plane *plane)
{
	(void) vars;
	(void) plane;
	t_complex_n ok;
	t_complex_n ko;
	ok.re = 0.;
	ok.im = -6.;
	ko.re = 5.;
	ko.im = 7;
	ko = multiply_complex(ok ,ko);
	// printf()
}
// void	newton(t_vars *vars, t_plane *plane)
// {
// 	int i = 0;
// 	int j = 0;
// 	int	n;
// 	t_complex_n z;
// 	t_complex_n	res1;
// 	t_complex_n	res2;
// 	t_complex_n	res3;

// 	res1.re = 1;
// 	res1.im = 0;

// 	res2.re = -0.5;
// 	res2.im = 1.732/2;

// 	res3.re = -0.5;
// 	res3.im = -1.732/2;
// 	(void) z;
// 	while (j < vars->size_win_y)
// 	{
// 		i = 0;
// 		while (i < vars->size_win_x)
// 		{
// 			z.re = plane->remin + i * plane->pixelsize;
// 			z.im = plane->immax - j * plane->pixelsize;
// 			n = 0;
// 			while (n < NMAX)
// 			{
// 				z -= divide_complex(z);
// 				n++;
// 				if (z)
// 			}
// 			// function()
// 		}
// 	}
					
// }

int	main(int ac, char **av)
{
	t_plane	plane;
	t_vars	vars;

	if (ac == 2)
	{
		if (parsing(av[1]) == MANDEL)
		{
			vars.fractal = MANDEL;
			init_plane_vars(&plane, &vars);
			mandel(plane, vars);
			mlx_mouse_hook(vars.win, mouse_hook, &vars);
			mlx_key_hook(vars.win, &keyhook, &vars);
			mlx_hook(vars.win, 33, 1L << 17, ft_close, &vars);
			mlx_loop(vars.mlx);
		}
		else if (parsing(av[1]) == JULIA)
		{
			init_plane_vars(&plane, &vars);
			mlx_loop(vars.mlx);
		}
		else if (parsing(av[1]) == NEWTON)
		{
			newton(&vars, &plane);
			vars.fractal = NEWTON;
			vars.mlx = mlx_init();
			vars.size_win_x = 630.;
			vars.size_win_y = 870.;
			plane.remin = -40;
			plane.remax = 40;
			plane.immin = -40;
			plane.immax = 40;
			plane.size_view = plane.remax - plane.remin;
			plane.size_view_y = plane.immax - plane.immin;
			plane.pixelsize = plane.size_view / 630;
			vars.win = mlx_new_window(vars.mlx, vars.size_win_x, vars.size_win_y,
			"Newton");
			mlx_hook(vars.win, 33, 1L << 17, ft_close, &vars);
			mlx_loop(vars.mlx);
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