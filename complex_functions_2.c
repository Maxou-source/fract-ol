/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 03:01:13 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/07 05:15:41 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_n	derivative(t_complex_n z)
{
	t_complex_n	tmp;

	tmp = multiply_complex(z);
	return (complex_by(tmp, 3));
}

int	plus_minus(t_complex_n z, t_complex_n res)
{
	t_complex_n	difference;
	float		tolerance;

	tolerance = 0.01;
	difference.re = z.re - res.re;
	difference.im = z.im - res.im;
	if (fabsl(difference.re) < tolerance && fabsl(difference.im) < tolerance)
		return (1);
	return (0);
}
