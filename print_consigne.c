/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_consigne.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 23:48:26 by mparisse          #+#    #+#             */
/*   Updated: 2022/12/25 23:48:28 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	print_consigne()
{
	ft_printf("Salut, bienvienue dans le projet fract-ol de Maximilien Parisse.\n");
	ft_printf("Voici les fractales disponible pour l'instant :\n");
	ft_printf(" -Mandelbrot -> écris : ./fractol Mandelbrot");
	ft_printf(" --petite description des travaux de Mandelbrot");
}
