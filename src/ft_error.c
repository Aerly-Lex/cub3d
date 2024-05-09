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
	int	i;

	i = -1;
	if (data->map && data->map->file)
		free_double_ptr(data->map->file);
	if (data->map && data->map->map2d)
		free_double_ptr(data->map->map2d);
	if (data->map && data->map->textures)
		free_double_ptr(data->map->textures);
	if (data->map)
		free(data->map);
	while (data->tex[++i])
		mlx_delete_image(data->mlx, data->tex[i]);
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
