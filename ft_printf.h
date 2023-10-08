#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


int	ft_putstr(const char *str);
void	ft_putnbru(unsigned long n);
void	ft_putnbr(long n);
void	print_p(unsigned long int n);
size_t	ft_putchar(const char c);
void print_X(unsigned int n, const char fmt);
int	len_print_X(unsigned int n, const char fmt);
int	len_print_p(unsigned long int n);
void	print_p(unsigned long int n);
int	print_i(int n);
int	print_u(unsigned int n);
int	format_int(va_list *ap, const char *fmt);
int	ft_printf(const char* fmt, ...);

#endif