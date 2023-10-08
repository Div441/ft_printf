#include "ft_printf.h"

int	format_int(va_list *ap, const char *fmt)
{
	int	count_f;

	count_f = 0;

	if (*fmt == 'c')
		count_f += ft_putchar(va_arg(*ap,int));
	else if (*fmt == '%')
		count_f += ft_putchar('%');
	else if(*fmt == 's')
		count_f += ft_putstr(va_arg(*ap, char *));
	else if(*fmt == 'p')	
		count_f += len_print_p((unsigned long)va_arg(*ap, void *));
	else if (*fmt == 'd' || *fmt == 'i')
		count_f += print_i(va_arg(*ap,int));
	else if (*fmt == 'u')
		count_f += print_u(va_arg(*ap,unsigned int));
	else if (*fmt == 'X' || *fmt == 'x')
		count_f += len_print_X(va_arg(*ap, unsigned int), *fmt);
	else
		count_f = -1;
	return (count_f);

}


int	ft_printf(const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	int	count;

	count = 0;
	if (!*fmt)
		return (0);
	while(*fmt != '\0')
	{
		if(*fmt != '%')
		{
			write(1,&(*fmt),1);
			count++;
			fmt++;
		}
		while(*fmt == '%' )
		{
			count += format_int(&ap, ++fmt);
			fmt++;
		}
	}
	va_end(ap);
	return (count);
}
/*
int	main()
{
	int x = ft_printf("%p\n",NULL);
	int y = printf("%p\n",NULL);
	printf("%d\n%d\n",x,y);
}*/