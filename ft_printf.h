# ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int		ft_printf(const char *, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int ft_print_address(unsigned long n);
int	ft_putnbr(long nb);
int	ft_print_hex(unsigned long n, char *base_hex);
int	count_len_nb(unsigned long nbr, int base, int sign);

# endif