/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelman <abdelman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:59:44 by abdelman          #+#    #+#             */
/*   Updated: 2026/11/06 14:42:42 by abdelman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_value(const char c , va_list args)
{
	int	lenght;

	lenght = 0;
	if (c == 'c')
		lenght += ft_putchar(va_arg(args, int));
	else if (c == 's')
		lenght += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		lenght += ft_print_address(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		lenght += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		lenght += ft_putnbr(va_arg(args, unsigned int));
	else if (c == 'x')
		lenght += ft_print_hex(va_arg(args, unsigned int),"0123456789abcdef");
	else if (c == 'X')
		lenght += ft_print_hex(va_arg(args, unsigned int),"0123456789ABCDEF");
	else if (c == '%')
		lenght += ft_putchar('%');
	return (lenght);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	lenght;
	va_list args;

	if (!format)
		return (0);
	va_start(args, format);
	lenght = 0;
	i = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			lenght += ft_print_value(format[i + 1], args);
			i++;
		}
		else
			lenght += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (lenght);
}