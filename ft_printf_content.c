/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelman <abdelman@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 09:55:22 by abdelman          #+#    #+#             */
/*   Updated: 2026/11/06 15:11:54 by abdelman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;
	char	*n;

	n = "(null)";
	if (!s)
		return (ft_putstr(n));
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int ft_print_address(unsigned long n)
{
	ft_putstr("0x");
	ft_print_hex(n,"0123456789abcdef");
	return (2+count_len_nb(n,16,1));
}

int	ft_putnbr(long nb)
{
	int		i;
	int		sign;
	int		arr[17];
	long	n;

	
	if (nb == 0)
		return (ft_putchar('0'), 1);
	if (nb < 0)
	{
		sign = (-1);
		nb = nb * -1;
		ft_putchar('-');
	}
	n = nb;
	i = 0;
	while (nb)
	{
		arr[i++] = nb % 10;
		nb /= 10;
	}
	while (--i >= 0)
		write(1, &"0123456789"[arr[i]], 1);
	return (count_len_nb(n,10,sign));
}

int	ft_print_hex(unsigned long n, char *base_hex)
{
	int	i;
	int arr[17];
	unsigned long	nb;

	i = 0;
	nb = n;
	if (n == 0)
		return (write(1, "0", 1), 1);
	while (n)
	{
		arr[i++] = n % 16;
		n /= 16;
	}
	while (--i >= 0)
		write(1,&base_hex[arr[i]],1);
	return (count_len_nb(nb, 16, 1));
}