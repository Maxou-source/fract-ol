/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:56:01 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/07 05:16:20 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	vars->mlx = 0;
	exit(0);
}

t_vars	change_color(t_vars *vars, int color)
{
	if (color == COLOR1)
		vars->color_shift = 1;
	if (color == COLOR2)
		vars->color_shift = 2;
	if (color == COLOR3)
		vars->color_shift = 3;
	return (*vars);
}
