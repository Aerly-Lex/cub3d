/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:13:08 by ajakob            #+#    #+#             */
/*   Updated: 2023/08/09 15:35:37 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strchr_gnl(const char *s, int c)
{
	char	*str;
	char	ch;
	int		i;

	if (!s)
		return (-1);
	str = (char *)s;
	ch = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return (i);
		i++;
	}
	if (str[i] == ch)
		return (i);
	return (-1);
}

void	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		i = 0;
	}
}

static char	*read_one(int fd, char *temp)
{
	char	*buffer;
	int		r_output;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	r_output = read(fd, buffer, BUFFER_SIZE);
	buffer[r_output] = '\0';
	if (r_output < 0)
	{
		free (temp);
		temp = NULL;
		free (buffer);
		return (NULL);
	}
	if (r_output == 0)
	{
		free (buffer);
		return (NULL);
	}
	return (buffer);
}

static char	*line_alloc(int fd, char **temp, char *line)
{
	char	*buffer;
	int		i;

	buffer = read_one(fd, *temp);
	if (!buffer)
		return (free(*temp), *temp = NULL, line);
	i = ft_strchr_gnl(buffer, '\n');
	while (i < 0)
	{
		line = ft_strjoin_gnl(line, buffer);
		buffer = read_one(fd, *temp);
		if (!buffer)
			return (free(*temp), *temp = NULL, line);
		i = ft_strchr_gnl(buffer, '\n');
	}
	if (i >= 0)
	{
		line = ft_strjoin_gnl(line, ft_not_free_substr_gnl(buffer, 0, i + 1));
		*temp = ft_substr_gnl(buffer, i + 1, BUFFER_SIZE - i);
		buffer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(temp), temp = NULL, NULL);
	line = NULL;
	if (temp)
	{
		i = ft_strchr_gnl(temp, '\n');
		if (i >= 0)
		{
			line = ft_strjoin_gnl(line, ft_not_free_substr_gnl(temp, 0, i + 1));
			temp = ft_substr_gnl(temp, i + 1, BUFFER_SIZE - i);
			return (line);
		}
		else if (i < 0)
		{
			line = ft_strjoin_gnl(line, temp);
			temp = NULL;
		}
	}
	return (line_alloc(fd, &temp, line));
}
