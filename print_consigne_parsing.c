/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_consigne_parsing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 23:48:26 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/07 15:58:39 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	print_consigne(void)
{
	ft_printf("Salut, bienvenue dans le projet fract-ol ");
	ft_printf("de Maximilien Parisse !!!\n\n");
	ft_printf("Voici les fractales que tu peux generer:\n\n");
	ft_printf(" -Ensemble de Mandelbrot -> écris : ");
	ft_printf("./fractol Mandelbrot \n\n");
	ft_printf(" -Ensemble de Julia  -> écris : ./fractol Julia x y\n");
	ft_printf("    Le generateur de Julia demande un nombre complex C\n");
	ft_printf("    x correspondant a la partie reel de C");
	ft_printf(" et y la partie imaginaire\n");
	ft_printf("    Celui ci va etre iteré NMAX nombre ");
	ft_printf("de fois par la fonction f(Z)\n");
	ft_printf("    tel que Zn+1 = Zn(carre) + C . \n\n");
	ft_printf("    Voici quelques valeurs de a et b donnant quelque chose de ");
	ft_printf("sympa visuellement :\n");
	ft_printf("\tles shurikens : 0.321 + 0.68i\n");
	ft_printf("\tles carreaux : -1.037 + 0.17i\n");
	ft_printf("\tle lapin de Douady : -0.1226 - 0.7449i \n\tet plein d'autres\n\n");
	ft_printf(" -Fractale de Newton -> écris : ./fractol Newton\n\n");
	ft_printf("Amuse-toi :)\n");
	return (EXIT_FAILURE);
}

int	parsing(char *str)
{
	if (ft_strcmp(str, "Mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(str, "Julia") == 0)
		return (2);
	else if (ft_strcmp(str, "Newton") == 0)
		return (3);
	return (0);
}

int	parsing_av(char **av)
{
	int		i;
	char	*real;
	char	*imagin;

	i = -1;
	real = av[2];
	imagin = av[3];
	while (real[++i])
	{
		if (ft_isdigit(real[i]) == 0 && (real[i] != '.'
				&& real[i] != '-' && real[i] != '+'))
			return (0);
	}
	i = -1;
	while (imagin[++i])
	{
		if (ft_isdigit(imagin[i]) == 0 && (imagin[i] != '.'
				&& imagin[i] != '-' && imagin[i] != '+'))
			return (0);
	}
	return (1);
}

void	free_mlx(t_vars *vars)
{
	free(vars->win);
	free(vars->mlx);
}
