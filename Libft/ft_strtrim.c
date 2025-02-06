/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:42:43 by frbranda          #+#    #+#             */
/*   Updated: 2024/05/09 13:29:33 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, (int)s1[start]))
		start++;
	while (end > start && ft_strrchr(set, (int)s1[end - 1]))
		end--;
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!str || !s1)
		return (NULL);
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
/* 
int	main(void)
{
	char	s1[] = " Hello World ";
	char	set[] = " ";

	printf("%s\n", ft_strtrim(s1, set));
} */