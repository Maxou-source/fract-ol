/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:16:57 by mparisse          #+#    #+#             */
/*   Updated: 2022/12/24 14:22:36 by mparisse         ###   ########.fr       */
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

t_plane	find_new_plane(t_plane plane)
{
	float	keep;
	float	keep2;
	float	a;
	float	b;

	// keep = plane.size_view;
	// plane.size_view = SCALE * plane.size_view;
	a = (SCALE * plane.size_view) - plane.size_view;
	// keep2 = plane.size_view_y;
	// plane.size_view_y = SCALE * plane.size_view_y;
	b = (SCALE * plane.size_view_y) - plane.size_view_y;

	plane.remin = plane.remin - (a * plane.xratio);
	plane.remax = plane.remax + (a * (1 - plane.xratio));
	plane.immax = plane.immax + (b * plane.yratio);
	plane.immin = plane.immin - (b * (1 - plane.yratio));
	plane.size_view = plane.remax - plane.remin;
	plane.size_view_y = plane.immax - plane.immin;
	plane.pixelsize = plane.size_view / 1000;
	return (plane);
}

int	keyhook(int key_code, t_vars *vars, t_data *img)
{
	int	x;
	int y;
	float xratio;
	float yratio;

	printf("key code : %d\n", key_code);
	yratio = y / vars->size_win_y;
	// printf("remin : %f", vars->size_win_x);
	printf("remin : %f \n", (vars->plane->remin));
	// printf("re : %d \nim : %d", x, y);
	if (key_code == 111)
	{
		// mlx_clear_window(vars->mlx, vars->win);
		mlx_mouse_get_pos(vars->mlx ,vars->win, &x, &y);
		printf("x : %d y : %d\n", x , y);
		(vars->plane->xratio) = x / vars->size_win_x;
		(vars->plane->yratio) = y / vars->size_win_y;
		*(vars->plane) = find_new_plane(*(vars->plane));
		// *(vars->plane) = decrement_plane(*(vars->plane));
		mandel(*(vars->plane), *vars);
	}
	if (key_code == 108)
	{
		// mlx_clear_window(vars->mlx, vars->win);
		*(vars->plane) = increment_plane(*(vars->plane));
		mandel(*(vars->plane), *vars);
	}
	if (key_code == 65362)
	{
		// mlx_clear_window(vars->mlx, vars->win);
		*(vars->plane) = plane_to_up(*(vars->plane));
		mandel(*(vars->plane), *vars);
	}
	if (key_code == 65364)
	{
		// mlx_clear_window(vars->mlx, vars->win);
		*(vars->plane) = plane_to_down(*(vars->plane));
		mandel(*(vars->plane), *vars);
	}
	if (key_code == 65361)
	{
		*(vars->plane) = plane_to_left(*(vars->plane));
		mandel(*(vars->plane), *vars);
	}
	if (key_code == 65363)
	{
		*(vars->plane) = plane_to_right(*(vars->plane));
		mandel(*(vars->plane), *vars);
	}
	if (key_code == 65307 || key_code == 113)
	{
		mlx_clear_window(vars->mlx, vars->win);
		// mlx_loop_end(vars->mlx);
		// mlx_destroy_image(vars->mlx, img->img);
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
