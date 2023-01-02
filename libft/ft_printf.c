/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:59:14 by mparisse          #+#    #+#             */
/*   Updated: 2022/11/18 23:29:11 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv(char c, va_list *args)
{
	long unsigned		p;
	intptr_t			num;

	if (c == 's')
		return (ft_putstr(va_arg(*args, const char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 'd' || c == 'i' || c == 'u')
	{
		num = va_arg(*args, int);
		if (num < 0 && c != 'u')
			return (ft_putchar('-') + ft_putnbr((unsigned)num * -1, 10, 0));
		return (ft_putnbr((unsigned)num, 10, 0));
	}
	else if (c == 'x' || c == 'X')
		return (ft_putnbr(va_arg(*args, unsigned int), 16,
				(c == 'X')));
	else if (c == 'p')
	{
		p = (uintptr_t)va_arg(*args, void *);
		if (!p)
			return (write(1, "(nil)", 5));
		return (ft_putstr("0x") + ft_putnbr(p, 16, 0));
	}
	return (ft_putchar(c));
}
/*
static int	check_numb_conv(const char *str)
{
	int	i;
	int	j;
	int	cpt;
	char 	*dif_type;
	
	i = 0;
	cpt = 0;
	dif_type = malloc(sizeof(char) * 10);
	dif_type = "cspdiuxX%";
	while (str[i])
	{
		j = 9;
		if (str[i] == '%')
		{
			j = 0;
			while (dif_type[j] != str[i+1] && dif_type[j])
				j++;
		}
		i++;
		if (j != 9)
			cpt++;			
	}
	return (cpt); 
}*/

int	ft_printf(const char *formats, ...)
{
	int		i;
	int		printed_out;
	va_list	args;

	i = 0;
	printed_out = 0;
	va_start(args, formats);
	while (formats[i])
	{
		if (formats[i] == '%')
			printed_out += conv(formats[++i], &args);
		else
			printed_out += ft_putchar(formats[i]);
		i++;
	}
	va_end (args);
	return (printed_out);
}
/*
int main()
{
	//check_numb = 
	char *str = "ca dit quoi";
	ft_printf("%s \n", str);
	//int i;
	//i = printf("lol\n");
	//printf("%d \n", i);
}*/
