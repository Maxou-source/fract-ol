/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:35:01 by mparisse          #+#    #+#             */
/*   Updated: 2023/01/07 18:05:08 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*\*/
static int	is_space(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

float	ft_atold(char *str)
{
	int		i;
	float	res;
	int		negatif;
	int		count_post_coma;
	float	post_coma;

	res = 0;
	i = 0;
	post_coma = 0;
	count_post_coma = 0;
	negatif = 1;
	while (is_space(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negatif = negatif * -1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1 && str[i] != '.')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '.')
		return (res * negatif);
	i++;
	while (ft_isdigit(str[i]) == 1)
	{
		post_coma = post_coma * 10 + (str[i] - '0');
		i++;
		count_post_coma++;
	}
	if (negatif == -1)
		return (res * negatif - (post_coma / pow(10, count_post_coma)));
	return (res * negatif + (post_coma / pow(10, count_post_coma)));
}
/**/