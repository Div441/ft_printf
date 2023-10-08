#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	count;

	count = 0;
	if(str == (char *)NULL)
	{ 
		write (1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		write (1, &(*str++), 1);
		count++;
	}
	return (count);
}

void	ft_putnbru(unsigned long n)
{
	unsigned char c;
	
	if (n < 10)
		{
			c = n + '0';
			write(1, &c, 1);
		}
	else
		{
			ft_putnbru(n / 10);
			c = (n % 10) + '0';
			write(1, &c, 1);
		}
	
}
void	ft_putnbr(long n)
{
	char	c;

	if (n == -2147483648)
		write (1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
			ft_putnbr(n);
		}
		else if (n < 10)
		{
			c = n + '0';
			write(1, &c, 1);
		}
		else
		{
			ft_putnbr(n / 10);
			c = (n % 10) + '0';
			write(1, &c, 1);
		}
	}
}
size_t	ft_putchar(const char c)
{
	return (write(1, &c, 1));
}
void print_X(unsigned int n, const char fmt)

{
	if (n >= 16)
	{
		print_X((n / 16), fmt);
		print_X((n % 16), fmt);
	}
	else 
	{
		if(n < 10)
		{
			ft_putchar(n + '0');
		}
		else if (n >= 10 && fmt == 'x')
			ft_putchar(n - 10 + 'a');
		else if (n >= 10 && fmt == 'X')
			ft_putchar(n - 10 +'A');
			
	}
	return ;
}

