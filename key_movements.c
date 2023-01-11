/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:35:28 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/07 05:16:06 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_plane	plane_to_up(t_vars *vars)
{
	t_plane	*plane;

	plane = vars->plane;
	plane->immin += plane->size_view_y * 0.05;
	plane->immax += plane->size_view_y * 0.05;
	plane->size_view = plane->remax - plane->remin;
	plane->pixelsize = plane->size_view / vars->size_win_x;
	return (*plane);
}

t_plane	plane_to_down(t_vars *vars)
{
	t_plane	*plane;

	plane = vars->plane;
	plane->immin -= plane->size_view_y * 0.05;
	plane->immax -= plane->size_view_y * 0.05;
	plane->size_view = plane->remax - plane->remin;
	plane->pixelsize = plane->size_view / vars->size_win_x;
	return (*plane);
}

t_plane	plane_to_left(t_vars *vars)
{
	t_plane	*plane;

	plane = vars->plane;
	plane->remin -= plane->size_view * 0.05;
	plane->remax -= plane->size_view * 0.05;
	plane->size_view = plane->remax - plane->remin;
	plane->pixelsize = plane->size_view / vars->size_win_x;
	return (*plane);
}

t_plane	plane_to_right(t_vars *vars)
{
	t_plane	*plane;

	plane = vars->plane;
	plane->remin += plane->size_view * 0.05;
	plane->remax += plane->size_view * 0.05;
	plane->size_view = plane->remax - plane->remin;
	plane->pixelsize = plane->size_view / vars->size_win_x;
	return (*plane);
}
// 0.00000000/