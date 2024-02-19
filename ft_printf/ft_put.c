/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavina <msavina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:21:16 by msavina           #+#    #+#             */
/*   Updated: 2023/11/08 14:35:24 by msavina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n, int base)
{
	int		count;
	char	*nmb;

	nmb = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		if (count < 0)
			return (-1);
		n = -n;
	}
	if (n < base)
		count += ft_putchar(nmb[n]);
	else
	{
		count += ft_putnbr(n / base, base);
		if (count < 0)
			return (-1);
		count += ft_putnbr(n % base, base);
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	ft_puthexup(long n, int base)
{
	int		count;
	char	*nmb;

	nmb = "0123456789ABCDEF";
	count = 0;
	if (n < base)
		count += ft_putchar(nmb[n]);
	else
	{
		count += ft_puthexup(n / base, base);
		if (count < 0)
			return (-1);
		count += ft_puthexup(n % base, base);
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		count += ft_putchar((int) *s);
		if (count < 0)
			return (-1);
		s++;
	}
	return (count);
}

int	ft_puthexlow(size_t n, int base)
{
	int		count;
	char	*nmb;

	nmb = "0123456789abcdef";
	count = 0;
	if (n < (size_t)base)
		count += ft_putchar(nmb[n]);
	else
	{
		count += ft_putnbr(n / base, base);
		if (count < 0)
			return (-1);
		count += ft_putnbr(n % base, base);
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	ft_putptr(size_t ptr)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	count += write(1, "0x", 2);
	if (count < 0)
		return (-1);
	count += ft_puthexlow(ptr, 16);
	if (count < 0)
		return (-1);
	return (count);
}
