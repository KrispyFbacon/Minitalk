/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_mini.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:10:30 by frbranda          #+#    #+#             */
/*   Updated: 2024/08/05 14:13:44 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_mini(char *s1, char c)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1)
	{
		str = (char *) ft_calloc(2, sizeof(char));
		if (!str)
			exit (EXIT_FAILURE);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	str = (char *) ft_calloc((ft_strlen(s1) + 2), sizeof(char));
	if (!str)
		exit (EXIT_FAILURE);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s1);
	return (str);
}
/*
int	main (void)
{
	char	*s1 = NULL;
	
	s1 = ft_strjoin_mini(s1, '1');
	ft_printf("%s\n", s1);
	s1 = ft_strjoin_mini(s1, 'A');
	ft_printf("%s\n", s1);
}*/