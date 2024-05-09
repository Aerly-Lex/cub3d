/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:23:23 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/04/11 16:21:53 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *c)
{
	int	len;

	len = 0;
	if (c == NULL)
		return (0);
	while (c[len] != '\0')
		len++;
	return (len);
}

char	*gnl_strchr(char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new_s;
	size_t	s1_len;
	size_t	s2_len;
	size_t	counter;

	counter = 0;
	if (!s1 && !s2)
		return (NULL);
	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	new_s = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (new_s == NULL)
		return (NULL);
	while (counter++ < s1_len)
		new_s[counter - 1] = s1[counter - 1];
	counter = 0;
	while (counter < s2_len)
	{
		new_s[s1_len + counter] = s2[counter];
		counter++;
	}
	new_s[s1_len + s2_len] = '\0';
	free(s1);
	return (new_s);
}

char	*line_grabber(char *remainder)
{
	char	*line;
	int		counter;

	counter = 0;
	if (remainder[counter] == '\0')
		return (NULL);
	while (remainder[counter] != '\0' && remainder[counter] != '\n')
		counter++;
	if (remainder[counter] == '\n')
		counter++;
	line = malloc(sizeof(char) * (counter + 1));
	if (!line)
		return (NULL);
	counter = 0;
	while (remainder[counter] != '\0' && remainder[counter] != '\n')
	{
		line[counter] = remainder[counter];
		counter++;
	}
	if (remainder[counter] == '\n')
		line[counter++] = '\n';
	line[counter] = '\0';
	return (line);
}

char	*remainder_refresh(char *remainder)
{
	char	*new_remainder;
	int		counter;
	int		new_counter;

	counter = 0;
	new_counter = 0;
	if (remainder[counter] == '\0')
		return (free(remainder), NULL);
	while (remainder[counter] != '\0' && remainder[counter] != '\n')
		counter++;
	if (remainder[counter] == '\n')
		counter++;
	new_remainder = malloc(sizeof(char) * (gnl_strlen(remainder) - counter + 1));
	if (new_remainder == NULL)
		return (free(remainder), NULL);
	while (remainder[counter] != '\0')
		new_remainder[new_counter++] = remainder[counter++];
	new_remainder[new_counter] = '\0';
	free(remainder);
	return (new_remainder);
}
