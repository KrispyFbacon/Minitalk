/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:22:10 by frbranda          #+#    #+#             */
/*   Updated: 2024/05/14 14:44:13 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p_s;

	p_s = (char *)s;
	while (n > 0)
	{
		*p_s = 0;
		p_s++;
		n--;
	}
}
/*
int	main(void)
{
	char	s[] = "Hello,World!";

	ft_bzero(s, 2);
	printf ("%s\n", s);
}*/
/*
int	main(void)
{
	char	s[] = "Hello,World!";
	char *ok = &s[5];

	ft_bzero(s, 4);
	printf ("%s\n", ok);
}*/
