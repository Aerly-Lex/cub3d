/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:01:28 by ajakob            #+#    #+#             */
/*   Updated: 2024/05/07 11:53:35 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_map_size(char *argv)
{
	char	*tmp;
	int		fd;
	int		y;

	fd = open(argv, O_RDONLY);
	y = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		y++;
	}
	close(fd);
	return (y);
}

void	free_double_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	ptr = NULL;
}

void	r_skip_spaces(char **file, int *y, int *x)
{
	(*x)--;
	while (file[*y][*x] && (file[*y][*x] == ' '
		|| file[*y][*x] == '\t' || file[*y][*x] == '\n'))
		(*x)--;
}

void	skip_spaces(char **file, int *y, int *x)
{
	while (file[*y] && file[*y][*x] && (file[*y][*x] == ' '
		|| file[*y][*x] == '\t' || file[*y][*x] == '\n'))
	{
		if (file[*y][*x] == '\n')
		{
			(*y)++;
			(*x) = 0;
		}
		else
			(*x)++;
	}
}

void	werror_ignore_free(char *str)
{
	free(str);
}
