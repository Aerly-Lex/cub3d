/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:29:10 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/05/05 15:46:15 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_check_file(t_data *data, int argc, char *argv)
{
	int	fd;
	int	i;

	if (argc != 2)
		ft_error(data, "Wrong number of arguments\n");
	fd = open(argv, O_RDONLY);
	i = 0;
	if (fd == -1)
		ft_error(data, "Can't open file\n");
	close(fd);
	while (argv[i] != '\0')
		i++;
	i -= 4;
	if (ft_strlen(argv) <= 4)
		ft_error(data, "You've found the Easter Egg.\n");
	if (ft_strcmp(&argv[i], ".cub"))
		ft_error(data, "Invalid name\n");
}

static char	**ft_create_file(t_data *data, char **argv)
{
	char	**file;
	int		map_size;
	int		fd;
	int		i;

	map_size = ft_map_size(argv[1]);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	file = ft_calloc(sizeof(char *), map_size + 1);
	if (!file)
		ft_error(data, "Allocation Failed\n");
	file[map_size] = NULL;
	while (i < map_size)
		file[i++] = get_next_line(fd);
	close(fd);
	return (file);
}

static void	ft_find_player(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map2d[y])
	{
		x = 0;
		while (map->map2d[y][x])
		{
			if (map->map2d[y][x] == 'N' || map->map2d[y][x] == 'S' ||
				map->map2d[y][x] == 'W' || map->map2d[y][x] == 'E')
			{
				map->direction = map->map2d[y][x];
				map->x_player = x;
				map->y_player = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	ft_width_height(t_map *map)
{
	int	y;

	y = 0;
	while (map->map2d[y])
		y++;
	map->m_height = y;
	if (map->map2d[0])
		map->m_width = ft_strlen(map->map2d[0]);
}

void	ft_init_map(t_data *data, int argc, char **argv)
{
	t_map	*map;
	char	**file;

	ft_check_file(data, argc, argv[1]);
	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		ft_error(data, "Allocation Failed\n");
	data->map = map;
	map->file = ft_create_file(data, argv);
	map->textures = ft_create_textures(data);
	map->map2d = ft_create_map2d(data);
	ft_find_player(map);
	ft_width_height(map);
}
