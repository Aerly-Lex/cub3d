/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:12:48 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/05/09 16:01:27 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_player(t_data *data)
{
	data->player.player_x = data->map->x_player * TILE + TILE / 2;
	data->player.player_y = data->map->y_player * TILE + TILE / 2;
	data->player.fov_rad = (FOV * M_PI) / 180;
	if (data->map->direction == 'N')
		data->player.p_angle = 3 * M_PI / 2;
	else if (data->map->direction == 'S')
		data->player.p_angle = M_PI / 2;
	else if (data->map->direction == 'E')
		data->player.p_angle = 0;
	else if (data->map->direction == 'W')
		data->player.p_angle = M_PI;
}

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "Test", false);
	if (!data->mlx)
		ft_error(data, "MLX_INIT failed\n");
	data->window = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->window)
		ft_error(data, "MLX_NEW_IMAGE failed\n");
	if (mlx_image_to_window(data->mlx, data->window, 0, 0) < 0)
		ft_error(data, "MLX_IMAGE_TO_WINDOW failed\n");
}

void	ft_game(void	*param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_delete_image(data->mlx, data->window);
	data->window = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	ft_hooks(data);
	raycast(data);
	mlx_image_to_window(data->mlx, data->window, 0, 0);
}

void	ft_init(int argc, char **argv, t_data *data)
{
	ft_init_map(data, argc, argv);
	ft_init_player(data);
	ft_init_mlx(data);
	load_colors(data->map);
	load_textures(data->map, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_init(argc, argv, &data);
	if (!mlx_loop_hook(data.mlx, ft_game, &data))
		ft_error(&data, "MLX_LOOP_HOOK failed\n");
	mlx_key_hook(data.mlx, &ft_keys, &data);
	mlx_loop(data.mlx);
	liberator(&data);
	return (0);
}
