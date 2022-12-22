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

#include "fract-ol.h"

// int	is_a_mandelbroot_set()
// {
	
// }
// Zn+1 =Zn(carre) + c

#define NMAX 200
#define	SIZERE 1000
#define SIZEIM 1000
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
	
	// printf("z = %f + %fi\n", zr, zi);
	// printf("c = %.2f + %.2fi\n", cr, ci);
	
	float x = pow(zr, 2) - pow(zi, 2) + cr; //reelle 
	float y = 2 * zr * zi + ci; //image
	// printf("x + iy = %.4f + %.4fi\n", x, y);
	
	res.re = x;
	res.im = y;
	return (res);
}

float	check(t_complex_n z)
{
	float	a;
	float	b;

	a = pow(z.re, 2);
	b = pow(z.im, 2);
	a = a + b;
	return (a);
}

int     keyhook(int key_code, t_vars *init)
{
    (void) key_code;
    printf("key code : %d\n", key_code);
    return (0);
    //mlx_loop_end(init);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int     close(t_vars *vars)
{
    // mlx_destroy_display(vars);
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
    // return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	t_plane	plane;

	printf("%s \n",av[1]);
	printf("ac : %d", ac);
	// if (ac == 2)
	// {
	// 	if (av[1] != "Mandelbroot")
	// 		return (0);
	// }
	// else
	// 	return (0);
	plane.remin = -2;
	plane.remax = 2;
	plane.immin = -1;
	plane.immax = 1;
	plane.size_view = plane.remax - plane.remin;
	plane.pixelsize = plane.size_view/1000;

	vars.mlx = mlx_init();
	vars.size_win_x = 1000;
	vars.size_win_y = 500;
	vars.win = mlx_new_window(vars.mlx, vars.size_win_x, vars.size_win_y, "Mandelbroot");
	// init_vars(vars);
	img.img = mlx_new_image(vars.mlx, vars.size_win_x, vars.size_win_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	int	i_win_x;
	int	j;
	i_win_x = 0;
	j = 0;
	t_complex_n cc;
	while (j < vars.size_win_y)
	{
		i_win_x = 0;
		while (i_win_x < vars.size_win_x)
		{
			cc.re = plane.remin + i_win_x * plane.pixelsize; 
			cc.im = plane.immax - j * plane.pixelsize;
			// printf("nombre complex c : re : %f im : %f \n", cc.re, cc.im);
	    	// my_mlx_pixel_put(&img, i_win_x, j, 0x00FF544);
			t_complex_n zz;
			t_complex_n tmp;
			tmp.re = 0;
			tmp.im = 0;
			zz.re = 0;
			zz.im = 0;
			int	n = 0;	
			while (n < NMAX)
			{
				// printf("tmp : %f + %fi \n", tmp.re, tmp.im);
				tmp = function(tmp, cc);
				zz = tmp;
				n++;
				// printf("%d \n", n);
				if (check(zz) >= 4)
					break;
			}
			if (n != NMAX)
				my_mlx_pixel_put(&img, i_win_x, j, 0x001693);
				// printf("okokoko\nokokok\n");
			i_win_x++;
		}
	    my_mlx_pixel_put(&img, i_win_x, j, 0x00FF544);
		j++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    mlx_key_hook(vars.win, &keyhook, &vars);
    mlx_hook(vars.win, 33, 1L<<17, close, &vars);
	mlx_loop(vars.mlx);
	// ok = 2.5;
	// printf("%f", ok);
}
