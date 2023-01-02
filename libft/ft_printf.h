/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:04:26 by mparisse          #+#    #+#             */
/*   Updated: 2022/11/18 23:29:01 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# define BASE "0123456789abcdef0123456789ABCDEF"

int	ft_putstr(const char *str);
int	ft_printf(const char *formats, ...);
int	ft_putchar(int c);
int	ft_putnbr(uintptr_t n, uintptr_t len_base, int upper);
//int	ft_putnbr_modif(int nb);
//int	ft_put_unsigned(unsigned int n);

#endif
