/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:44:46 by ajakob            #+#    #+#             */
/*   Updated: 2024/05/05 16:01:21 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_if_chars_are_valid(t_data *data, char **file)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	y = 0;
	while (file[y])
	{
		x = 0;
		while (file[y][x])
		{
			if (file[y][x] != ' ' && file[y][x] != '1' && file[y][x] != '0'
				&& file[y][x] != 'N' && file[y][x] != 'S' && file[y][x] != 'E'
				&& file[y][x] != 'W' && file[y][x] != '\n')
				ft_error(data, "Invalid char or chars in map\n");
			if (file[y][x] == 'N' || file[y][x] == 'S'
				|| file[y][x] == 'E' || file[y][x] == 'W')
				i++;
			x++;
		}
		y++;
	}
	if (i != 1)
		ft_error(data, "Invalid amount of players\n");
}

static void	check_for_new_lines(t_data *data, char **file)
{
	int	y;
	int	x;

	y = 0;
	while (file[y])
	{
		if (!ft_strchr(file[y], '1'))
		{
			while (file[y] && !ft_strchr(file[y], '1')
				&& !ft_strchr(file[y], '0'))
				y++;
			if (file[y] && (ft_strchr(file[y], '1') || ft_strchr(file[y], '0')))
				ft_error(data, "Second map found\n");
			y--;
		}
		y++;
	}
}

static int	check_middle_walls(t_data *data, char **file)
{
	int	y;
	int	x;

	y = 1;
	x = 0;
	while (file[y + 1])
	{
		x = 0;
		if (!ft_strchr(file[y], '1'))
		{
			y--;
			break ;
		}
		skip_spaces(file, &y, &x);
		if (file[y][x] != '1')
			ft_error(data, "Invalid middle wall\n");
		x = ft_strlen(file[y]);
		r_skip_spaces(file, &y, &x);
		if (file[y][x] != '1')
			ft_error(data, "Invalid middle wall\n");
		y++;
	}
	return (y);
}

static void	check_outer_walls(t_data *data, char **file)
{
	int	y;
	int	x;

	x = 0;
	while (file[0][x])
	{
		if (file[0][x] != '1' && file[0][x] != '\n' && file[0][x] != ' ')
			ft_error(data, "Invalid first wall\n");
		x++;
	}
	y = 1;
	x = 0;
	y = check_middle_walls(data, file);
	while (file[y][x])
	{
		if (file[y][x] && file[y][x] != '1'
			&& file[y][x] != '\n' && file[y][x] != ' ')
			ft_error(data, "Invalid last wall\n");
		x++;
	}
}

char	**ft_create_map2d(t_data *data)
{
	char	**file;

	file = data->map->file;
	check_if_chars_are_valid(data, file);
	check_for_new_lines(data, file);
	check_outer_walls(data, file);
	check_flood_fill(data, file);
	return (file);
}
