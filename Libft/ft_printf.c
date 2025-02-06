/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:52:55 by frbranda          #+#    #+#             */
/*   Updated: 2024/07/25 13:16:25 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_format(va_list args, char format)
{
	int		count;

	count = 0;
	if (format == 'c')
		count = count + ft_putchar_pf(va_arg(args, int), 1);
	else if (format == 's')
		count = count + ft_putstr_pf(va_arg(args, char *), 1);
	else if (format == 'd' || format == 'i')
		count = count + ft_putnbr_pf((long)va_arg(args, int), 1);
	else if (format == 'u')
		count = count + ft_putnbr_pf(va_arg(args, unsigned int), 1);
	else if (format == 'p')
		count = count + ft_putnbr_base_p(va_arg(args, unsigned long), 16,
				"0123456789abcdef");
	else if (format == 'x')
		count = count + ft_putnbr_base(va_arg(args, unsigned int), 16,
				"0123456789abcdef");
	else if (format == 'X')
		count = count + ft_putnbr_base(va_arg(args, unsigned int), 16,
				"0123456789ABCDEF");
	else if (format == '%')
		count = count + ft_putchar_pf('%', 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (0);
	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			count = count + printf_format(args, *(++format));
			count--;
		}
		else
			write(1, format, 1);
		count++;
		if (*format != '\0')
			format++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	int	count;

	count = ft_printf("My: %c %s", 'A', "Hello");
	printf("\nCount Mine: %d\n", count);
	count = printf("Or: %c %s", 'A', "Hello");
	printf("\nCount Original: %d\n\n", count);
	
	count = ft_printf("My: %d %u %%", -2147483648, 1234);
	printf("\nCount Mine: %d\n", count);
	count = printf("Or: %ld %u %%", -2147483648, 1234);
	printf("\nCount Original: %d\n\n", count);

	count = ft_printf("My: %x %X", 42, 42);
	printf("\nCount Mine: %d\n", count);
	count = printf("Or: %x %X", 42, 42);
	printf("\nCount Original: %d\n\n", count);
	
	count = ft_printf("My: %p %p", 1234, 0);
	printf("\nCount Mine: %d\n", count);
	count = printf("Or: %p %p", 0x1234, 0);
	printf("\nCount Original: %d\n\n", count);

	ft_printf("teste%");
	printf("\nteste%"); 
}*/