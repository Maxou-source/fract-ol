/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_stuff_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:35:28 by mparisse          #+#    #+#             */
/*   Updated: 2022/12/25 14:35:49 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

t_plane	decrement_plane(t_plane plane)
{
	plane.remin = plane.remin + 0.1;
	plane.remax = plane.remax - 0.1;
	plane.immin = plane.immin + 0.1;
	plane.immax = plane.immax - 0.1;
	plane.size_view = plane.remax - plane.remin;
	plane.pixelsize = plane.size_view / 1000;
	return (plane);
}

t_plane	increment_plane(t_plane plane)
{
	plane.remin = plane.remin - 0.1;
	plane.remax = plane.remax + 0.1;
	plane.immin = plane.immin - 0.1;
	plane.immax = plane.immax + 0.1;
	plane.size_view = plane.remax - plane.remin;
	plane.pixelsize = plane.size_view / 1000;
	return (plane);
}

// left gauche
// right droite

t_plane	plane_to_left(t_plane plane)
{
	plane.remin = plane.remin - 0.1;
	plane.remax = plane.remax - 0.1;
	plane.size_view = plane.remax - plane.remin;
	plane.pixelsize = plane.size_view / 1000;
	return (plane);
}

t_plane	plane_to_right(t_plane plane)
{
	plane.remin = plane.remin + 0.1;
	plane.remax = plane.remax + 0.1;
	plane.size_view = plane.remax - plane.remin;
	plane.pixelsize = plane.size_view / 1000;
	return (plane);
}