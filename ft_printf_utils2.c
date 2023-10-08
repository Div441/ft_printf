#include "ft_printf.h"

int	len_print_X(unsigned int n, const char fmt)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	print_X(n , fmt);
	while(n)
	{
		n /= 16;
		i++;
	}
	return (i);

}
int	len_print_p(unsigned long int n)
{
	int	i;

	i = 0;
	write(1,"0x",2);
	if (n == 0)
		i = 1;
	print_p(n);
	while(n)
	{
		n /= 16;
		i++;
	}
	return (i + 2);

}
void	print_p(unsigned long int n)
{
	if (n >= 16)
	{
		print_p((n / 16));
		print_p((n % 16));
	}
	else 
	{
		if(n < 10)
		{
			ft_putchar(n + '0');
		}
		else if (n >= 10)
			ft_putchar(n - 10 + 'a');
			
	}
	return ;
}

int	print_i(int n)
{
	int len;
	long	num;

	len = 0;
	num = n;
	if (n <= 0)
		len = 1;
	ft_putnbr(num);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	print_u(unsigned int n)
{
	int len;
	unsigned long int	num;

	len = 0;
	num = n;
	if(n == 0)
		len = 1;
	ft_putnbru(num);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}