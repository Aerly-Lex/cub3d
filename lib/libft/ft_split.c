/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:14:51 by Dscheffn          #+#    #+#             */
/*   Updated: 2023/10/17 14:11:25 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlen_deli(char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static size_t	c_occurences(char *s, char c)
{
	size_t	occurences;
	int		in_word;

	in_word = 0;
	occurences = 0;
	while (*s != '\0')
	{
		if (*s != c && in_word == 0)
			in_word = 1;
		else if (*s == c && in_word == 1)
		{
			occurences++;
			in_word = 0;
		}
		s++;
	}
	if (in_word == 1)
		occurences++;
	if (0 == occurences)
		return (0);
	return (occurences);
}

static char	**liberator(char **splitted_s, size_t counter)
{
	while (counter > 0)
	{
		free(splitted_s[--counter]);
	}
	free(splitted_s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted_s;
	size_t	s_len;
	size_t	counter;

	counter = 0;
	splitted_s = malloc(sizeof(char *) * (c_occurences((char *)s, c) + 1));
	if (splitted_s == NULL || (c_occurences((char *)s, c) == 0))
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		s_len = strlen_deli((char *)s, c);
		splitted_s[counter] = malloc(sizeof(char) * s_len + 1);
		if (splitted_s[counter] == NULL)
			return (liberator(splitted_s, counter));
		ft_strlcpy(splitted_s[counter], s, s_len +1);
		counter++;
		s += s_len;
	}
	splitted_s[counter] = NULL;
	return (splitted_s);
}

//everytime a delimiter appears in a str, split the str into an array of strs

// int	main(void)
// {
// 	char	s1[] = "xxxxxxxxhello!xxxx  Hi";
// 	char	c = 'x';
// 	char	**new_s;
// 	int		counter = 0;

// 	new_s =	ft_split(s1, c);
// 	while (new_s[counter] != NULL)
// 	{
// 		printf("Split %d:%s\n", counter, new_s[counter]);
// 		counter++;
// 	}
// 	return (0);
// }
