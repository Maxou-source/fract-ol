/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:16:57 by mparisse          #+#    #+#             */
/*   Updated: 2022/12/28 00:31:42 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	vars->mlx = 0;
	exit(0);
}

int mouse_hook(int button, int x,int y, t_vars *vars)
{
	if (button == 4)
	{
		(vars->plane->xratio) = x / vars->size_win_x;
		(vars->plane->yratio) = y / vars->size_win_y;
		*(vars->plane) = find_new_plane_in(*(vars->plane));
		mandel(*(vars->plane), *vars);
	}
	if (button == 5)
	{
		(vars->plane->xratio) = x / vars->size_win_x;
		(vars->plane->yratio) = y / vars->size_win_y;
		*(vars->plane) = find_new_plane_out(*(vars->plane));
		mandel(*(vars->plane), *vars);
	}
	printf("x: %d | y: %d\n", x, y);
	return (0);
}

int	keyhook(int key_code, t_vars *vars, t_data *img)
{
	(void) img;
	printf("keycode : %d \n", key_code);
	if (key_code == UP)
	{
		// mlx_clear_window(vars->mlx, vars->win);
		*(vars->plane) = plane_to_up(*(vars->plane));
		mandel(*(vars->plane), *vars);
	}
	else if (key_code == DOWN)
	{
		if (vars->fractal == MANDEL)
		{
		*(vars->plane) = plane_to_down(*(vars->plane));
		mandel(*(vars->plane), *vars);
		}
	}
	else if (key_code == LEFT)
	{
		*(vars->plane) = plane_to_left(*(vars->plane));
		mandel(*(vars->plane), *vars);
	}
	else if (key_code == RIGHT)
	{
		*(vars->plane) = plane_to_right(*(vars->plane));
		mandel(*(vars->plane), *vars);
	}
	else if (key_code == 65307 || key_code == 113)
	{
		mlx_clear_window(vars->mlx, vars->win);
		// mlx_loop_end(vars->mlx);
		ft_close(vars);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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
