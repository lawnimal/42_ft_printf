/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavina <msavina@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:11:07 by msavina           #+#    #+#             */
/*   Updated: 2023/11/08 16:35:37 by msavina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/// @brief converts, formats & prints its arguments on the std output under
/// under control of the format. 
/// @param  const char *fmt = mutable ptr to an immutale char/fmt to which s
// points. Const applies to char, not the asterisk.https://elearning.intra.42.fr/
/// @param  ... = ellipsis, tells the compiler, that there will be an unknown
// nmb of arguments
/// @return the number of char printed

int	ft_fmt(char s, va_list args);

static int	ft_printff(const char *fmt, va_list args, int i)
{
	int	count;

	count = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			count += ft_fmt(fmt[++i], args);
			if (count < 0)
				return (-1);
		}
		else
		{
			count += write(1, &fmt[i], 1);
			if (count < 0)
				return (-1);
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, fmt);
	if (!fmt)
		return (-1);
	count = ft_printff(fmt, args, i);
	va_end(args);
	return (count);
}

int	ft_fmt(char s, va_list args)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (s == '%')
		count = write(1, "%", 1);
	else if (s == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (s == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (s == 'i' || s == 'd')
		count = ft_putnbr((long)(va_arg(args, int)), 10);
	else if (s == 'p')
		count = ft_putptr((size_t)va_arg(args, void *));
	else if (s == 'u')
		count = ft_putnbr(va_arg(args, unsigned int), 10);
	else if (s == 'x')
		count = ft_puthexlow((long)(va_arg(args, unsigned int)), 16);
	else if (s == 'X')
		count = ft_puthexup((long)(va_arg(args, unsigned int)), 16);
	else if (count < 0)
		return (-1);
	return (count);
}

// int	main()
// {
// 	int	count;
// 	count = ft_printf("Hello %s\n", "world");
// 	ft_printf("The chars written are %d\n", count);
// 	ft_printf("Magic %s is %d\n", "number", -42);
// 	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
// 	printf("The chars written are %d\n", count);
// 	printf("Magic %s is %d\n", "number", 42);
// 	printf("Hexadecimal for %d is %x\n", 42, 42);
// 	return (0);
// }