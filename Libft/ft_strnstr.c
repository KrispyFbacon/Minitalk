/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:48:59 by frbranda          #+#    #+#             */
/*   Updated: 2024/05/13 12:08:14 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!big && !len)
		return (0);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i] == little[j] && i < len)
		{
			i++;
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i - j]);
		}
		i = i - j;
		i++;
	}
	return (NULL);
}
/* 
#include <bsd/string.h>

int	main(void)
{
	char	*big = "Hello WWorld World my name is Bacon";
	char	*little = "World";
	size_t	n = 16;

	printf ("%s\n", ft_strnstr(big, little, n));
	printf ("%s\n", strnstr(big, little, n));
} */
