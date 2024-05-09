/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:33:00 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/05/09 16:01:44 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	liberator(t_data *data)
{
	if (data->map->file)
		free_double_ptr(data->map->file);
	if (data->map->map2d)
		free_double_ptr(data->map->map2d);
	if (data->map->textures)
		free_double_ptr(data->map->textures);
	if (data->map)
		free(data->map);
	if (data->tex[NORTH])
		mlx_delete_image(data->mlx, data->tex[NORTH]);
	if (data->tex[SOUTH])
		mlx_delete_image(data->mlx, data->tex[SOUTH]);
	if (data->tex[WEST])
		mlx_delete_image(data->mlx, data->tex[WEST]);
	if (data->tex[EAST])
		mlx_delete_image(data->mlx, data->tex[EAST]);
	if (data->mlx)
		mlx_terminate(data->mlx);
}

// Cleans and exits the program as failure.
void	ft_error(t_data *data, char *str)
{
	printf("Error\n");
	if (str)
		printf("%s", str);
	liberator(data);
	exit(-1);
}
