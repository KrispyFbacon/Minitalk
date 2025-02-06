/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:19:08 by frbranda          #+#    #+#             */
/*   Updated: 2024/07/25 13:04:09 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_putnbr_base_p(unsigned long n, unsigned int base, char *digits)
{
	int	len;

	len = 0;
	if (n >= base)
		len = len + ft_write_putnbr_base_p(n / base, base, digits);
	write (1, &digits[n % base], 1);
	len++;
	return (len);
}

int	ft_putnbr_base_p(unsigned long n, unsigned int base, char *digits)
{
	int	len;

	len = 0;
	if (!n)
		return (write (1, "(nil)", 5));
	write (1, "0x", 2);
	len = 2;
	len = len + ft_write_putnbr_base_p(n, base, digits);
	return (len);
}
/* 
int	main(void)
{
	int				count;
	void			*ptr = (void *)0x123b;
	unsigned int	base = 16;
	char			*digits = "0123456789abcdef";

	count = ft_putnbr_base_p(ptr, base, digits);
	printf("\nCount Mine: %i\n", ptr);
	return 0;
} */