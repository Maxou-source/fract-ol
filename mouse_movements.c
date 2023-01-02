/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:17:11 by mparisse          #+#    #+#             */
/*   Updated: 2022/12/31 15:02:37 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

t_plane	find_new_plane_in(t_plane plane)
{
	double	a;
	double	b;

	a = (SCALE * plane.size_view) - plane.size_view;
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

t_plane	find_new_plane_out(t_plane plane)
{
	double	a;
	double	b;

	a = (1/SCALE * plane.size_view) - plane.size_view;
	b = (1/SCALE * plane.size_view_y) - plane.size_view_y;
	plane.remin = plane.remin - (a * plane.xratio);
	plane.remax = plane.remax + (a * (1 - plane.xratio));
	plane.immax = plane.immax + (b * plane.yratio);
	plane.immin = plane.immin - (b * (1 - plane.yratio));
	plane.size_view = plane.remax - plane.remin;
	plane.size_view_y = plane.immax - plane.immin;
	plane.pixelsize = plane.size_view / 1000;
	return (plane);
}
