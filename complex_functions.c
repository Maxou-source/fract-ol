/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 02:46:56 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/07 05:15:45 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_n	divide_complex(t_complex_n arg1, t_complex_n arg2)
{
	t_complex_n	res;
	float		a;
	float		b;
	float		c;
	float		d;

	a = arg2.re;
	b = arg2.im;
	c = arg1.re;
	d = arg1.im;
	res.re = ((c * a) + (b * d)) / (pow(a, 2) + pow(b, 2));
	res.im = ((a * d) - (c * b)) / (pow(a, 2) + pow(b, 2));
	return (res);
}

t_complex_n	multiply_complex(t_complex_n arg1)
{
	t_complex_n	res;
	float		a;
	float		b;

	a = arg1.re;
	b = arg1.im;
	res.re = pow(a, 2) - pow(b, 2);
	res.im = 2 * a * b;
	return (res);
}

t_complex_n	complex_by(t_complex_n z, float x)
{
	z.re = z.re * x;
	z.im = z.im * x;
	return (z);
}

t_complex_n	cubed_complex(t_complex_n z)
{
	t_complex_n	res;
	float		a;
	float		b;

	a = z.re;
	b = z.im;
	res.re = pow(a, 3) - (3 *(a * pow(b, 2)));
	res.im = (3 * pow(a, 2) * b) - pow(b, 3);
	return (res);
}
// printf("res : %Lf + %Lfi \n", res.re, res.im);

t_complex_n	function_minus(t_complex_n z)
{
	z = cubed_complex(z);
	z.re = z.re - 1;
	return (z);
}
