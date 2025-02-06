/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:02:32 by frbranda          #+#    #+#             */
/*   Updated: 2024/05/15 10:44:43 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*pdest;
	const char	*psrc;

	pdest = (char *)dest;
	psrc = (const char *)src;
	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	while (n > 0)
	{
		*pdest = *psrc;
		pdest++;
		psrc++;
		n--;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[100] = "Hello";
	char	dest[100];

	printf("%s", (char *)ft_memcpy(dest, src , 20));
} */
