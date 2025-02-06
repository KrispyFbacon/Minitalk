/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:07:03 by frbranda          #+#    #+#             */
/*   Updated: 2024/07/25 13:04:20 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int n, unsigned int base, char *digits)
{
	int	len;

	len = 0;
	if (n >= base)
		len = len + ft_putnbr_base(n / base, base, digits);
	write (1, &digits[n % base], 1);
	len++;
	return (len);
}
/* 
int	main(void)
{
	int				count;
	unsigned int	n = 42;
	unsigned int	base = 16;
	char			*digits = "0123456789abcdef";

	count = ft_putnbr_base(n, base, digits);
	printf("\nCount Mine: %d\n", count);
}*/