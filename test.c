/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:06:23 by mparisse          #+#    #+#             */
/*   Updated: 2022/12/15 22:32:18 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include <stdio.h>
#include "fract-ol.h"

int     keyhook(int key_code, t_vars *init)
{
    (void) key_code;
    printf("key code : %d\n", key_code);
    return (0);
    //mlx_loop_end(init);
}

int     close(t_vars *vars)
{
    // mlx_destroy_display(vars);
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
    // return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    draw_circle(int x, int y, int rayon, t_data img)
{
    const double PI = 3.1415926535;
    double i, angle, x1, y1;

    while (i< 360)
    {
        angle = i;
        x1 = rayon * cos(angle * PI / 180);
        y1 = rayon * sin(angle * PI / 180);
        my_mlx_pixel_put(&img, x + x1, y + y1, 0x00FF544);
        i += 0.1;
    }
}

// void    draw_triangle()

int	main(void)
{
    t_vars  vars;
	t_data	img;
    // int     i = 0;
    t_middle    middle;
    t_circle     circle;

	vars.mlx = mlx_init();
    vars.size_win_x = 1000;
    vars.size_win_y = 1000;
    middle.middle_x = vars.size_win_x / 2;
    middle.middle_y = vars.size_win_y / 2;
	vars.win = mlx_new_window(vars.mlx, vars.size_win_x, vars.size_win_y, "Hello world!");
	img.img = mlx_new_image(vars.mlx, vars.size_win_x, vars.size_win_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    circle.rayon = 500;
    circle.diametres = circle.rayon * 2;
    draw_circle(middle.middle_x, middle.middle_y, circle.rayon, img);
    // my_mlx_pixel_put(&img, middle.middle_x + circle.rayon, middle.middle_y, 0x00FF544);
    // my_mlx_pixel_put(&img, middle.middle_x + circle.rayon, middle.middle_y, 0x00FF544);
    // for (int i = 0; i < 400; i++)
    // while (i < 400)
    // {
	//     my_mlx_pixel_put(&img, 100 + i, 100, 0x00FF544 + i);
	//     my_mlx_pixel_put(&img, 100 + i, 500, 0x00FF544 + i);
    //     i++;
    // }
    // printf("100 + i = %d", 100 + i);
    // i = 0;
    // while (i < 400)
    // {
	//     my_mlx_pixel_put(&img, 100, 100 + i, 0x00FF544 + i);
	//     my_mlx_pixel_put(&img, 500, 100 + i, 0x00FF544 + i);
    //     i++;
    // }
    my_mlx_pixel_put(&img, middle.middle_x, middle.middle_y, 0x00FF544);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    mlx_key_hook(vars.win, &keyhook, &vars);
    mlx_hook(vars.win, 33, 1L<<17, close, &vars);
	mlx_loop(vars.mlx);
}

// int main()
// {
//     t_vars  vars;
//     t_data img;
//     // vars = malloc(sizeof(t_vars));
//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 400, 400, "New Window");
    
//     mlx_hook(vars.win, 33, 1L<<17, close, &vars);
//     mlx_key_hook(vars.win, &keyhook, &vars);
//     // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 	// 							&img.endian);
//     // for (int i = 0; i < 50; i++) {
//     //     my_mlx_pixel_put(& img, 150 + i, 300 + i, 0x7455 + i);
//     // }
//     mlx_loop(vars.mlx);
// }