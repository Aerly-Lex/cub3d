/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:56:10 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/05/09 15:22:02 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Opens from Data->map->textures[i] the pictures
// and load them into data->texture[0-3]
void	load_textures(t_map *map, t_data *data)
{
	mlx_texture_t	*tmp;

	tmp = mlx_load_png(map->textures[0]);
	data->tex[NORTH] = mlx_texture_to_image(data->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png(map->textures[1]);
	data->tex[SOUTH] = mlx_texture_to_image(data->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png(map->textures[2]);
	data->tex[WEST] = mlx_texture_to_image(data->mlx, tmp);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png(map->textures[3]);
	data->tex[EAST] = mlx_texture_to_image(data->mlx, tmp);
	mlx_delete_texture(tmp);
	free_double_ptr(map->textures);
	if (data->tex[NORTH] == NULL || data->tex[SOUTH] == NULL
		|| data->tex[WEST] == NULL || data->tex[EAST] == NULL)
		ft_error(data, "Could not load texture\n");
}
