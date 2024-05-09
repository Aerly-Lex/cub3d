/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:33:00 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/05/09 17:23:55 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	liberator(t_data *data)
{
	if (data->map->file)
	{
		printf("No\n");
		free_double_ptr(data->map->file);
	}
	printf("1\n");
	if (data->map->map2d)
		free_double_ptr(data->map->map2d);
	printf("2\n");
	if (data->map->textures)
		free_double_ptr(data->map->textures);
	printf("3\n");
	if (data->map)
		free(data->map);
	printf("4\n");
	if (data->tex[NORTH])
		mlx_delete_image(data->mlx, data->tex[NORTH]);
	printf("NORTH\n");
	if (data->tex[SOUTH])
		mlx_delete_image(data->mlx, data->tex[SOUTH]);
	printf("SOUTH\n");
	if (data->tex[WEST])
		mlx_delete_image(data->mlx, data->tex[WEST]);
	printf("WEST\n");
	if (data->tex[EAST])
		mlx_delete_image(data->mlx, data->tex[EAST]);
	printf("5\n");
}

// Cleans and exits the program as failure.
void	ft_error(t_data *data, char *str)
{
	printf("Error\n");
	if (str)
		printf("%s", str);
	if (!data)
		exit(-1);
	liberator(data);
	exit(-1);
}
