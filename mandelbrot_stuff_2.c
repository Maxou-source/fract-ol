/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_stuff_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:04:09 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/02 20:01:15 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	mandel_calcul(t_vars vars, t_plane plane)
{
	int			i;
	int			j;
	int			n;
	int			rgb;
	t_complex_n	c;

	i = 0;
	j = 0;
	while (j < vars.size_win_y)
	{
		i = 0;
		while (i < vars.size_win_x)
		{
			c.re = plane.remin + i * plane.pixelsize;
			c.im = plane.immax - j * plane.pixelsize;
			n = is_mandel(c, vars);
			if (n != NMAX)
			{
				rgb = get_color(n / NMAX);
				my_mlx_pixel_put(vars.data, i, j, rgb + 100);
			}
			i++;
		}
		j++;
	}
}
