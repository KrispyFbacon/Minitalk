/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:55:17 by frbranda          #+#    #+#             */
/*   Updated: 2024/05/14 16:17:41 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	j;
	size_t	i;

	j = 0;
	i = start;
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs || !s)
		return (NULL);
	while (s[i] != '\0' && i < len + start)
	{
		subs[j] = s[i];
		i++;
		j++;
	}
	subs[j] = '\0';
	return (subs);
}
/* 
int	main(void)
{
	printf ("%s\n", ft_substr("abcde", 2, 5));
}  */