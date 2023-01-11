/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:16:57 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/07 18:05:29 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_movements(int key_button, t_vars *vars, int key_mouse)
{
	if (key_mouse == 0)
	{
		if (key_button == UP)
			mandel(plane_to_up(vars), *vars);
		if (key_button == DOWN)
			mandel(plane_to_down(vars), *vars);
		if (key_button == LEFT)
			mandel(plane_to_left(vars), *vars);
		if (key_button == RIGHT)
			mandel(plane_to_right(vars), *vars);
		if (key_button >= COLOR1 && key_button <= COLOR3)
			mandel(*vars->plane, change_color(vars, key_button));
		else if (key_button == 65307 || key_button == 113)
		{
			mlx_clear_window(vars->mlx, vars->win);
			ft_close(vars);
		}
	}
	if (key_mouse == 1)
	{
		if (key_button == 4)
			mandel(find_new_plane_in(vars, vars->plane), *vars);
		if (key_button == 5)
			mandel(find_new_plane_out(vars, vars->plane), *vars);
	}
}

void	julia_movements(int key_button, t_vars *vars, int key_mouse)
{
	if (key_mouse == 0)
	{
		if (key_button == UP)
			julia(plane_to_up(vars), *vars);
		if (key_button == DOWN)
			julia(plane_to_down(vars), *vars);
		if (key_button == LEFT)
			julia(plane_to_left(vars), *vars);
		if (key_button == RIGHT)
			julia(plane_to_right(vars), *vars);
		if (key_button >= COLOR1 && key_button <= COLOR3)
			julia(*vars->plane, change_color(vars, key_button));
		else if (key_button == 65307 || key_button == 113)
		{
			mlx_clear_window(vars->mlx, vars->win);
			ft_close(vars);
		}
	}
	if (key_mouse == 1)
	{
		if (key_button == 4)
			julia(find_new_plane_in(vars, vars->plane), *vars);
		if (key_button == 5)
			julia(find_new_plane_out(vars, vars->plane), *vars);
	}
}

void	newton_movements(int key_button, t_vars *vars, int key_mouse)
{
	if (key_mouse == 0)
	{
		if (key_button == UP)
			newton(plane_to_up(vars), *vars);
		if (key_button == DOWN)
			newton(plane_to_down(vars), *vars);
		if (key_button == LEFT)
			newton(plane_to_left(vars), *vars);
		if (key_button == RIGHT)
			newton(plane_to_right(vars), *vars);
		if (key_button == COLOR1 || key_button == COLOR2)
			newton(*vars->plane, change_color(vars, key_button));
		else if (key_button == 65307 || key_button == 113)
		{
			mlx_clear_window(vars->mlx, vars->win);
			ft_close(vars);
		}
	}
	if (key_mouse == 1)
	{
		if (key_button == 4)
			newton(find_new_plane_in(vars, vars->plane), *vars);
		if (key_button == 5)
			newton(find_new_plane_out(vars, vars->plane), *vars);
	}
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	vars->posx = x;
	vars->posy = y;
	if (vars->fractal == MANDEL)
		mandel_movements(button, vars, 1);
	if (vars->fractal == JULIA)
		julia_movements(button, vars, 1);
	if (vars->fractal == NEWTON)
		newton_movements(button, vars, 1);
	return (0);
}

// 0 key 
// 1 mouse

int	keyhook(int key_code, t_vars *vars)
{
	if (vars->fractal == MANDEL)
		mandel_movements(key_code, vars, 0);
	if (vars->fractal == JULIA)
		julia_movements(key_code, vars, 0);
	if (vars->fractal == NEWTON)
		newton_movements(key_code, vars, 0);
	else if (key_code == 65307 || key_code == 113)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_loop_end(vars->mlx);
		ft_close(vars);
	}
	return (0);
}

// void	init_plane_vars(t_plane *plane, t_vars *vars)
// {
// 	plane->remin = -2.0;
// 	plane->remax = 2.0;
// 	plane->immin = -1.0;
// 	plane->immax = 1.0;
// 	plane->size_view = plane->remax - plane->remin;
// 	plane->size_view_y = plane->immax - plane->immin;
// 	plane->pixelsize = plane->size_view / 1000;
// 	plane->pixelsize_y = plane->size_view_y / 500;
// 	vars->mlx = mlx_init();
// 	vars->size_win_x = 1000.;
// 	vars->size_win_y = 500.;
// 	vars->win = mlx_new_window(vars->mlx, vars->size_win_x, vars->size_win_y,
// 			"Mandelbrot");
// 	vars->plane = plane;
// }
