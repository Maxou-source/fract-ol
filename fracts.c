/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 06:36:12 by mparisse          #+#    #+#             */
/*   Updated: 2022/12/16 20:53:59 by mparisse         ###   ########.fr       */
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

	res.x = arg.x * arg.x;
	res.y = arg.y * arg.y;
	printf("res x : %f \n", res.x);
	printf("res y : %f \n", res.y );
	return (res);
}

t_complex_n sum_up(t_complex_n arg1, t_complex_n arg2)
{
	t_complex_n res;

	res.x = arg1.x + arg2.x;
	res.y = arg1.y + arg2.y;
	return (res);
}

t_complex_n	square_root(t_complex_n arg)
{
	t_complex_n	res;
	
	res.x = sqrt(arg.x);
	res.y = sqrt(arg.y);
	return (res);
}

float	sum_up_stuff(t_complex_n n)
{
	float res;

	res = n.x + n.y;
	return (res);
}

// b negatif -> 

t_complex_n	function(t_complex_n arg, t_complex_n arg_before)
{
	t_complex_n	res;
	t_complex_n	arg_b_two;
	float	a;
	float	b;
	
	a = arg_before.x;
	b = arg_before.y;
	float res_x = (a * a) + arg.x + arg_before.y; 
	// printf("a * a + arg.x : %f \n", a * a + arg.x);
	printf("res_x : %f \n", res_x);
	res_x = (a * a) + arg.x - arg_before.y; 
	printf("res_x : %f \n", res_x);
	res.x = (arg_before.x * arg_before.x) + arg_before.x;
	res.y = (arg_before.y * arg_before.y) + arg_before.y;
	return (res);
}

int	main(int ac, char **av)
{
	t_complex_n	big_c;
	t_complex_n small_n;

	big_c.x = 0.5;
	big_c.y = 0.5;
	small_n.x = 0.5;
	small_n.y = 0.5;
	
	big_c = function(big_c,small_n);
	// big_c = sum_up(big_c, small_n);
	printf("x : %f \n", big_c.x);
	printf("y : %f \n", big_c.y );
	// ok = 2.5;
	// printf("%f", ok);
}
