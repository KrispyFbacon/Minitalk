/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:33:03 by frbranda          #+#    #+#             */
/*   Updated: 2024/04/23 17:18:57 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
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
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n <= 9 && flag != 1)
	{
		num = n + '0';
		write (fd, &num, 1);
	}
}
/*
int	main(void)
{
	ft_putnbr_fd(-2147483647, 1);
}*/
