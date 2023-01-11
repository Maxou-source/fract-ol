/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_stuff_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:04:09 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/09 19:54:10 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	is_mandel(t_complex_n c)
{
	t_complex_n	z;
	t_complex_n	tmp;
	float		n;

	tmp.re = 0;
	tmp.im = 0;
	z.re = 0;
	z.im = 0;
	n = 0;
	while (n < NMAX)
	{
		tmp = function(tmp, c);
		z = tmp;
		n++;
		if (check(z) >= 4)
			break ;
	}
	return (n);
}

int	plus_minus_color(float t, float origin)
{
	float	tolerance;

	tolerance = 0.1;
	if (t >= origin - tolerance && t <= origin - tolerance)
		return (1);
	return (0);
}

int	get_color(float t, int color_shift)
{
	float	rgb[4];

	rgb[3] = 0;
	rgb[0] = 9.0 * (1 - t) * pow(t, 3) * 255.0;
	rgb[1] = 15.0 * pow((1 - t), 2) * pow(t, 2) * 255.0;
	rgb[2] = 8.5 * pow((1 - t), 3) * t * 255.0;
	if (color_shift == 2)
	{
		rgb[3] = 0;
		rgb[1] = 9.0 * (1 - t) * pow(t, 3) * 255.0;
		rgb[0] = 15.0 * pow((1 - t), 2) * pow(t, 2) * 255.0;
		rgb[2] = 8.5 * pow((1 - t), 3) * t * 255.0;
		return (((int)rgb[0] << 16) | ((int)rgb[1] << 8) | ((int)rgb[2]));
	}
	if (color_shift == 3)
	{
		rgb[3] = 0;
		rgb[0] = 9.0 * (1 - t) * pow(t, 3) * 255.0;
		rgb[1] = 15.0 * pow((1 - t), 2) * pow(t, 2) * 255.0;
		rgb[2] = 8.5 * pow((1 - t), 3) * t * 255.0;
		return (((int)rgb[0] << 16) | ((int)rgb[1] << 8) | ((int)rgb[2]));
	}
	return (((int)rgb[0] << 16) | ((int)rgb[1] << 8) | ((int)rgb[2]));
}
