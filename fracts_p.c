/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracts_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:14:38 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/09 23:24:32 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel(t_plane plane, t_vars vars)
{
	init_img(& vars.data, &vars);
	mandel_calcul(vars, plane);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
	mlx_destroy_image(vars.mlx, vars.data.img);
}

void	julia(t_plane plane, t_vars vars)
{
	init_img(& vars.data, &vars);
	julia_calcul(plane, vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
	mlx_destroy_image(vars.mlx, vars.data.img);
}

void	newton(t_plane plane, t_vars vars)
{
	init_img(& vars.data, &vars);
	newton_calcul(plane, vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
	mlx_destroy_image(vars.mlx, vars.data.img);
}

void	start_fractal(t_vars vars, t_plane plane,
			void f(t_plane plane, t_vars vars))
{
	f(plane, vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, &keyhook, &vars);
	mlx_hook(vars.win, 33, 1L << 17, ft_close, &vars);
	mlx_loop(vars.mlx);
}

int	main(int ac, char **av)
{
	int					res_pars;
	static t_func		funcs[3] = {& mandel, & julia, & newton};
	t_plane				plane;
	t_vars				vars;

	if (ac != 2 && ac != 4)
		return (print_consigne());
	res_pars = parsing(av[1]);
	if (res_pars <= 0 || res_pars > 3)
		return (print_consigne());
	else if (ac == 2 && res_pars == MANDEL)
		init_plane_vars_mandel(&plane, &vars);
	else if (ac == 2 && res_pars == NEWTON)
		init_plane_vars_newton(&vars, &plane);
	else if (ac == 4 && res_pars == JULIA && parsing_av(av) == 1)
	{
		vars.fractal = JULIA;
		init_plane_vars_julia(&plane, &vars, av);
	}
	else
		return (print_consigne(), 0);
	start_fractal(vars, plane, funcs[res_pars - 1]);
	return (EXIT_SUCCESS);
}

// int main(int ac, char **av)
// {
// 	t_plane plane;
// 	t_vars vars;

// 	// if (parsing_av(av))
// 	if (ac == 2)
// 	{
// 		if (parsing(av[1]) == MANDEL)
// 		{
// 			vars.fractal = MANDEL;
// 			init_plane_vars_mandel(&plane, &vars);
// 			mandel(plane, vars);
// 			mlx_mouse_hook(vars.win, mouse_hook, &vars);
// 			mlx_key_hook(vars.win, &keyhook, &vars);
// 			mlx_hook(vars.win, 33, 1L << 17, ft_close, &vars);
// 			mlx_loop(vars.mlx);
// 		}
// 		else if (parsing(av[1]) == NEWTON)
// 		{
// 			init_plane_vars_newton(&vars, &plane);
// 			newton(vars, plane);
// 			mlx_mouse_hook(vars.win, mouse_hook, &vars);
// 			mlx_key_hook(vars.win, &keyhook, &vars);
// 			mlx_hook(vars.win, 33, 1L << 17, ft_close, &vars);
// 			mlx_loop(vars.mlx);
// 		}
// 		else 
// 			return (print_consigne(), 0);
// 	}
// 	else if (ac == 4 && parsing(av[1]) == JULIA && parsing_av(av)
// == 1) // && ft_atold(av[2]) && ft_atold(av[3]))
// 	{
// 		init_plane_vars_julia(&plane, &vars, av);
// 		julia(plane, vars);
// 		mlx_mouse_hook(vars.win, mouse_hook, &vars);
// 		mlx_key_hook(vars.win, &keyhook, &vars);
// 		mlx_hook(vars.win, 33, 1L << 17, ft_close, &vars);
// 		mlx_loop(vars.mlx);
// 	}
// 	else
// 	{
// 		print_consigne();
// 		return (0);
// 	}
// 	return (0);
// }

// print consigne (check)
// couleur 
// retour de la mlx (check)
// julia digits (check)

// norme si il en reste