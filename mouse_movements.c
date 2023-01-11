/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:17:11 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/07 05:16:27 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_plane	find_new_plane_in(t_vars *vars, t_plane *plane)
{
	float	a;
	float	b;

	plane->xratio = vars->posx / vars->size_win_x;
	plane->yratio = vars->posy / vars->size_win_y;
	a = (SCALE * plane->size_view) - plane->size_view;
	b = (SCALE * plane->size_view_y) - plane->size_view_y;
	plane->remin = plane->remin - (a * plane->xratio);
	plane->remax = plane->remax + (a * (1 - plane->xratio));
	plane->immax = plane->immax + (b * plane->yratio);
	plane->immin = plane->immin - (b * (1 - plane->yratio));
	plane->size_view = plane->remax - plane->remin;
	plane->size_view_y = plane->immax - plane->immin;
	plane->pixelsize = plane->size_view / vars->size_win_x;
	plane->pixelsize_y = plane->size_view_y / vars->size_win_y;
	return (*plane);
}

t_plane	find_new_plane_out(t_vars *vars, t_plane *plane)
{
	float	a;
	float	b;

	plane->xratio = vars->posx / vars->size_win_x;
	plane->yratio = vars->posy / vars->size_win_y;
	a = (1 / SCALE * plane->size_view) - plane->size_view;
	b = (1 / SCALE * plane->size_view_y) - plane->size_view_y;
	plane->remin = plane->remin - (a * plane->xratio);
	plane->remax = plane->remax + (a * (1 - plane->xratio));
	plane->immax = plane->immax + (b * plane->yratio);
	plane->immin = plane->immin - (b * (1 - plane->yratio));
	plane->size_view = plane->remax - plane->remin;
	plane->size_view_y = plane->immax - plane->immin;
	plane->pixelsize = plane->size_view / vars->size_win_x;
	return (*plane);
}
