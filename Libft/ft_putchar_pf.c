/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:48:09 by frbranda          #+#    #+#             */
/*   Updated: 2024/06/04 16:02:59 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(char c, int fd)
{
	int	count;

	write(fd, &c, 1);
	count = 1;
	return (count);
}
/* int	main(void)
{
	int	count;
	
	count = ft_putchar_pf('A', 1);
	printf ("\n%d", count);
} */