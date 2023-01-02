/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:35:28 by mparisse          #+#    #+#             */
/*   Updated: 2022/12/31 15:04:44 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

t_plane	plane_to_up(t_plane plane)
{
	plane.immin += plane.size_view_y * 0.05;
	plane.immax += plane.size_view_y * 0.05;
	plane.size_view = plane.remax - plane.remin;
	plane.pixelsize = plane.size_view / 1000;
	return (plane);	
}

t_plane	plane_to_down(t_plane plane)
{
	// printf("potentiel new plane immin :  %9.6Lf \n", SCALE * plane.immin);	
	// plane.immin -= plane.;
	// printf("immin : %9.6Lf \n", plane.immin);
	plane.immin -= plane.size_view_y * 0.05;
	plane.immax -= plane.size_view_y * 0.05;
	plane.size_view = plane.remax - plane.remin;
	plane.pixelsize = plane.size_view / 1000;
	return (plane);
}

t_plane	plane_to_left(t_plane plane)
{
	plane.remin -= plane.size_view * 0.05;
	plane.remax -= plane.size_view * 0.05;
	plane.size_view = plane.remax - plane.remin;
	plane.pixelsize = plane.size_view / 1000;
	return (plane);
}

t_plane	plane_to_right(t_plane plane)
{
	plane.remin += plane.size_view * 0.05;
	plane.remax += plane.size_view * 0.05;
	plane.size_view = plane.remax - plane.remin;
	plane.pixelsize = plane.size_view / 1000;
	return (plane);
}
// 0.00000000/