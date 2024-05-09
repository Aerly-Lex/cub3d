/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:56:03 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/04/11 16:22:11 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reader(int fd, char *remainder)
{
	char	*buff;
	int		bytes_reader;

	if (read(fd, 0, 0) < 0)
		return (free(remainder), NULL);
	bytes_reader = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	while (bytes_reader > 0 && gnl_strchr(remainder, '\n') == 0)
	{
		bytes_reader = read(fd, buff, BUFFER_SIZE);
		if (bytes_reader == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_reader] = '\0';
		remainder = gnl_strjoin(remainder, buff);
		if (remainder == 0)
			return (free(remainder), NULL);
	}
	free(buff);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	remainder = reader(fd, remainder);
	if (remainder == NULL)
		return (NULL);
	line = line_grabber(remainder);
	remainder = remainder_refresh(remainder);
	return (line);
}

// return Number of bytes read on success
// return 0 on reaching the end of file
// return -1 on error
// return -1 on signal interrupt

// #include <fcntl.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	*line;
// 	int		i = 1;
// 	// int		fd1;
// 	// int		fd2;
// 	int		fd3;
// 	// fd1 = open("tests/test.txt", O_RDONLY);
// 	// fd2 = open("tests/test1.txt", O_RDONLY);
// 	fd3 = open("tests/test2.txt", O_RDONLY);
// 	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
// 	while (i < 5)
// 	{
// 		// line = get_next_line(fd1);
// 		// printf("line1-%d: %s", i, line);
// 		// free(line);
// 		// line = get_next_line(fd2);
// 		// printf("line2-%d: %s", i, line);
// 		// free(line);
// 		line = get_next_line(fd3);
// 		printf("line3-%d: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	// close(fd1);
// 	// close(fd2);
// 	close(fd3);
// 	return (0);
// }
