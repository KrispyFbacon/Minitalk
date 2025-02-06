/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:44:42 by frbranda          #+#    #+#             */
/*   Updated: 2024/05/22 13:17:34 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (write(1, "(null)", 6));
	}
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
	return (i);
}
/* 
int	main(void)
{
	char	s[] = "Hello, World!";

	printf ("\n%d", ft_putstr_fd(s, 1));
} */
