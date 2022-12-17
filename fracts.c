/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 06:36:12 by mparisse          #+#    #+#             */
/*   Updated: 2022/12/17 18:02:41 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fract-ol.h"

// int	is_a_mandelbroot_set()
// {
	
// }
// Zn+1 =Zn(carre) + c

t_complex_n	power_of_two(t_complex_n arg)
{
	t_complex_n	res;

	res.re = arg.re * arg.re;
	res.im = arg.im * arg.im;
	printf("res re : %f \n", res.re);
	printf("res im : %f \n", res.im );
	return (res);
}

t_complex_n sum_up(t_complex_n arg1, t_complex_n arg2)
{
	t_complex_n res;

	res.re = arg1.re + arg2.re;
	res.im = arg1.im + arg2.im;
	return (res);
}

t_complex_n	square_root(t_complex_n arg)
{
	t_complex_n	res;
	
	res.re = sqrt(arg.re);
	res.im = sqrt(arg.im);
	return (res);
}

float	sum_up_stuff(t_complex_n n)
{
	float res;

	res = n.re + n.im;
	return (res);
}

// b negatif -> 

t_complex_n	function(t_complex_n arg1, t_complex_n arg2)
{
	t_complex_n	res;
	float	zr;
	float	zi;
	float	cr;
	float	ci;
	
	zr = arg1.re;
	zi = arg1.im;
	cr = arg2.re;
	ci = arg2.im;
	
	printf("z = %.2f + %.2fi\n", zr, zi);
	printf("c = %.2f + %.2fi\n", cr, ci);
	
	float x = pow(zr, 2) - pow(zi, 2) + cr; //reelle 
	float y = 2 * zr * zi + ci; //image
	printf("x + iy = %.4f + %.4fi\n\n", x, y);
	
	res.re = x;
	res.im = y;
	return (res);
}

int	main(int ac, char **av)
{
	t_complex_n	c;
	t_complex_n z;

	z.re = 0.5;
	z.im = 1;
	c.re = 0.5;
	c.im = 0.5;
	
	z = function(z,c);
	// c = sum_up(c, small_n);
	printf("re : %f \n", z.re);
	printf("im : %f \n", z.im );
	// ok = 2.5;
	// printf("%f", ok);
}
