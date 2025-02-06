/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:26:55 by frbranda          #+#    #+#             */
/*   Updated: 2024/05/14 16:51:58 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*put_itoa(long n, char *str, int len)
{
	int	i;

	i = len - 1;
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	long	nr;
	int		len;
	char	*str;

	nr = n;
	len = get_len(nr);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (put_itoa(nr, str, len));
}
/* 
int	main(void)
{
	int	i = -2147483648;
	printf("%d\n", get_len(i));
	printf("%s\n", ft_itoa(i));
} */