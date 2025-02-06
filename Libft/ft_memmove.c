/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:05:00 by frbranda          #+#    #+#             */
/*   Updated: 2024/05/03 12:57:07 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	if (p_dest > p_src)
	{
		while (n > 0)
		{
			n--;
			p_dest[n] = p_src[n];
		}
	}
	else
	{
		ft_memcpy(p_dest, p_src, n);
	}
	return (dest);
}
/*
int	main(void)
{
	size_t	n = 5;
	char	src[] = "Hello";
	char	dest[10];

	printf("%s", (char *)ft_memmove(dest, src , n));
} */
