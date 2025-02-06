/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbranda <frbranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:17:35 by frbranda          #+#    #+#             */
/*   Updated: 2024/05/15 11:03:37 by frbranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	ft_count_substr(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	ft_write_words(char const *s, char *dest, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		dest[j] = s[i - word_len];
		j++;
		word_len--;
	}
	dest[j] = '\0';
}

static char	**ft_split_words(char const *s, char c, char **str, int num_substr)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	while (word < num_substr)
	{
		word_len = 0;
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			i++;
			word_len++;
		}
		str[word] = (char *)ft_calloc((word_len + 1), (sizeof(char)));
		if (!str[word])
			return (ft_free(str), NULL);
		ft_write_words(s, str[word], i, word_len);
		word++;
	}
	str[word] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		num_substr;
	char	**str;

	num_substr = ft_count_substr(s, c);
	str = (char **)ft_calloc((num_substr + 1), sizeof(char *));
	if (!str)
		return (NULL);
	if (!(ft_split_words(s, c, str, num_substr)))
		return (NULL);
	return (str);
}
/* 
 #include "libft.h"

int	main(void)
{
	const char	*str = "111.222.333.444...555";
	char		**result;
	int			i;

	result = ft_split(str, '.');
	i = 0;
	if (!result)
	{
		printf("Memory allocation failed\n");
		return(0);
	}
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0); 
}*/
