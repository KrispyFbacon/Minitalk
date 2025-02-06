/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:06:13 by frbranda          #+#    #+#             */
/*   Updated: 2024/05/14 15:58:11 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p_s;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	p_s = (char *)ft_calloc(len + 1, 1);
	if (!p_s)
		return (NULL);
	while (s[i] != '\0')
	{
		p_s[i] = s[i];
		i++;
	}
	p_s[i] = '\0';
	return (p_s);
}
/* 
int	main(void)
{
	char	s[] = "Hello, World!";

	printf ("%s\n", ft_strdup(s));
} */
