/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:50:13 by mparisse          #+#    #+#             */
/*   Updated: 2022/12/17 16:09:18 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "mlx_linux/mlx.h"



typedef struct s_plane
{
	float	remin;
	float	remax;
	float	immin;
	float	immax;
	float	size_view;
	float	pixelsize;
} t_plane;

typedef struct s_vars {
    void    *mlx;
    void    *win;
	int		size_win_x;
	int		size_win_y;
}   t_vars;

typedef struct s_complex_n {
	float	re;
	float	im;
}	t_complex_n;

typedef struct s_middle
{
	int		middle_x;
	int		middle_y;
}	t_middle;

typedef struct s_circle
{
	int		rayon;
	int		diametres;
}	t_circle;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// t_vars    init_vars(t_vars vars);