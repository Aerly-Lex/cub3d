/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:36:22 by ajakob            #+#    #+#             */
/*   Updated: 2024/05/05 15:57:45 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**mod_alloc_because_norminette_is_a_pain(t_data *data, int y)
{
	char	**buffer;
	int		i;

	i = 0;
	while (data->map->file[y + i])
		i++;
	buffer = ft_calloc(sizeof(char *), i + 1);
	if (!buffer)
		ft_error(data, "Allocation Failed\n");
	return (buffer);
}

static int	mod_strlen(char **str, int y, int x, int len)
{
	int	max_len;

	max_len = 0;
	while (str[y])
	{
		if (len > max_len)
			max_len = len;
		len = 0;
		x = 0;
		while (str[y][x])
		{
			if (str[y][x] == '\t')
				len += 4;
			else
				len++;
			x++;
		}
		y++;
	}
	if (len > max_len)
		max_len = len;
	return (max_len);
}

static void	*mod_calloc(size_t num, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = num * size;
	ptr = malloc(total_size);
	if (ptr != NULL)
		ft_memset(ptr, ' ', total_size);
	return (ptr);
}

static char	*mod_strdup(char *s1, int len)
{
	char	*ptr;
	int		check;
	int		i;
	int		j;

	check = 0;
	i = 0;
	j = 0;
	ptr = mod_calloc(sizeof(char), len + 1);
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		if (s1[i] == '\t')
			j += 4;
		else if (s1[i] == '\n')
			check = 1;
		else
			ptr[j++] = s1[i];
		i++;
	}
	if (check == 1)
		ptr[len - 1] = '\n';
	ptr[len] = '\0';
	return (ptr);
}

void	realloc_file(t_data *data, char **file, int y)
{
	char	**buffer;
	int		i;
	int		j;

	buffer = mod_alloc_because_norminette_is_a_pain(data, y);
	i = 0;
	j = mod_strlen(file, y, 0, 0);
	while (file[y])
	{
		buffer[i] = mod_strdup(file[y], j);
		if (!buffer[i])
		{
			free_double_ptr(buffer);
			ft_error(data, "Allocation Failed\n");
		}
		i++;
		y++;
	}
	buffer[i] = NULL;
	free_double_ptr(data->map->file);
	data->map->file = buffer;
}
