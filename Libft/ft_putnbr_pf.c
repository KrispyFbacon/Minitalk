/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:50:06 by frbranda          #+#    #+#             */
/*   Updated: 2024/05/22 10:57:04 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write_putnbr(long n, int fd)
{
	char	num;
	int		flag;

	flag = 0;
	if (n == -2147483648 && flag == 0)
	{
		write (fd, "-2147483648", 11);
		flag = 1;
	}
	else if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_write_putnbr(n / 10, fd);
		ft_write_putnbr(n % 10, fd);
	}
	if (n <= 9 && flag != 1)
	{
		num = n + '0';
		write (fd, &num, 1);
	}
}

int	ft_putnbr_pf(long n, int fd)
{
	int		len;

	len = get_len_nbr(n);
	ft_write_putnbr(n, fd);
	return (len);
}
/*
int	main(void)
{
	ft_putnbr_pf(-2147483648, 1);
}*/
