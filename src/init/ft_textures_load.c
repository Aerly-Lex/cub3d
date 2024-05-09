/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_load.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:56:10 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/05/09 17:28:36 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Opens from Data->map->textures[i] the pictures
// and load them into data->texture[0-3]
void	load_textures(t_map *map, t_data *data)
{
	mlx_texture_t	*tmp;
	int				i;

	i = 0;
	while (i < DIRECTION_COUNT)
	{
		tmp = mlx_load_png(map->textures[i]);
		if (!tmp)
			ft_error(data, "Could not load png\n");
		data->tex[i] = mlx_texture_to_image(data->mlx, tmp);
		mlx_delete_texture(tmp);
		if (!data->tex[i])
			ft_error(data, "Could not load texture\n");
		i++;
	}
	free_double_ptr(map->textures);
	map->textures = NULL;
}
