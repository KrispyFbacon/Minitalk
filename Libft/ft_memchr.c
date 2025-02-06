/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:48:15 by frbranda          #+#    #+#             */
/*   Updated: 2024/04/29 11:15:33 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;
	unsigned char	p_c;
	size_t			i;

	p_s = (unsigned char *)s;
	p_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p_s[i] == p_c)
			return (&p_s[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	s[] = "Hello, World!";
	int		i = 'o';
	size_t	n = 7;


	printf("%s\n", (char *)ft_memchr(s, i, n));
	return (0);
} */
