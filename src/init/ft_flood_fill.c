/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:47:25 by ajakob            #+#    #+#             */
/*   Updated: 2024/05/05 16:01:30 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ffl(t_data *data, int x, int y, int max_y)
{
	char	**file;

	file = data->map->file;
	if (!(y >= 0 && x >= 0 && y < max_y
			&& x < (int)ft_strlen(file[y]) && file[y][x]))
		return ;
	else if (file[y][x] == 'N' || file[y][x] == 'S' ||
		file[y][x] == 'W' || file[y][x] == 'E' || file[y][x] == '0')
		ft_error(data, "FFL say's it's invalid!\n");
	else if (file[y][x] == ' ')
	{
		file[y][x] = '1';
		ffl(data, x + 1, y, max_y);
		ffl(data, x - 1, y, max_y);
		ffl(data, x, y + 1, max_y);
		ffl(data, x, y - 1, max_y);
		ffl(data, x - 1, y + 1, max_y);
		ffl(data, x + 1, y + 1, max_y);
		ffl(data, x - 1, y - 1, max_y);
		ffl(data, x + 1, y - 1, max_y);
	}
}

void	check_flood_fill(t_data *data, char **file)
{
	int	y;
	int	x;
	int	max_y;

	y = 0;
	max_y = 0;
	while (file[max_y])
		max_y++;
	while (file[y])
	{
		x = 0;
		while (file[y][x])
		{
			if (file[y][x] == ' ')
				ffl(data, x, y, max_y);
			x++;
		}
		y++;
	}
}
