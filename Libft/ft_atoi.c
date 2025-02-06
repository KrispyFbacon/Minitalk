/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:45:25 by frbranda          #+#    #+#             */
/*   Updated: 2024/04/30 16:09:23 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *c)
{
	int	i;
	int	sign;
	int	numb;

	i = 0;
	sign = 1;
	numb = 0;
	while (c[i] == ' ' || (c[i] >= 9 && c[i] <= 13))
		i++;
	if (c[i] == '-' || c[i] == '+')
	{
		if (c[i] == '-')
			sign = -1;
		i++;
	}
	while (c[i] >= '0' && c[i] <= '9')
	{
		numb = numb * 10;
		numb = numb + (c[i] - '0');
		i++;
	}
	return ((int)numb * sign);
}
/* 
int	main(void)
{
	char	c[] = "   -1234abd567!!!";

	printf ("%d\n", ft_atoi(c));
	return (0);
}  */