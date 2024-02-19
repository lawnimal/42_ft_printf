/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavina <msavina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:24:54 by msavina           #+#    #+#             */
/*   Updated: 2023/11/08 15:37:35 by msavina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
// # include <stdio.h>

int	ft_printf(const char *fmt, ...);
int	ft_putchar(int c);
int	ft_putnbr(long n, int base);
int	ft_puthexup(long n, int base);
int	ft_puthexlow(size_t n, int base);
int	ft_putstr(char *s);
int	ft_putptr(size_t ptr);

#endif