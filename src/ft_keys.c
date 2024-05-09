/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:28:56 by ajakob            #+#    #+#             */
/*   Updated: 2024/05/09 15:10:59 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	w_s_func(mlx_key_data_t keydata, t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)
		&& mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->player.w_s = 0;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
		&& !(mlx_is_key_down(data->mlx, MLX_KEY_W)
			&& mlx_is_key_down(data->mlx, MLX_KEY_S)))
		data->player.w_s = 1;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS
		&& !(mlx_is_key_down(data->mlx, MLX_KEY_W)
			&& mlx_is_key_down(data->mlx, MLX_KEY_S)))
		data->player.w_s = -1;
}

static void	a_d_func(mlx_key_data_t keydata, t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)
		&& mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->player.a_d = 0;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
		&& !(mlx_is_key_down(data->mlx, MLX_KEY_A)
			&& mlx_is_key_down(data->mlx, MLX_KEY_D)))
		data->player.a_d = 1;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
		&& !(mlx_is_key_down(data->mlx, MLX_KEY_A)
			&& mlx_is_key_down(data->mlx, MLX_KEY_D)))
		data->player.a_d = -1;
}

static void	rotate_func(mlx_key_data_t keydata, t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP)
		&& mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->player.rotate = 0;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS
		&& !(mlx_is_key_down(data->mlx, MLX_KEY_LEFT)
			&& mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)))
		data->player.rotate = -1;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS
		&& !(mlx_is_key_down(data->mlx, MLX_KEY_LEFT)
			&& mlx_is_key_down(data->mlx, MLX_KEY_RIGHT)))
		data->player.rotate = 1;
	if (mlx_is_key_down(data->mlx, MLX_KEY_Q)
		&& mlx_is_key_down(data->mlx, MLX_KEY_E))
		data->player.w_s = 0;
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS
		&& !(mlx_is_key_down(data->mlx, MLX_KEY_Q)
			&& mlx_is_key_down(data->mlx, MLX_KEY_E)))
		data->player.rotate = -1;
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS
		&& !(mlx_is_key_down(data->mlx, MLX_KEY_Q)
			&& mlx_is_key_down(data->mlx, MLX_KEY_E)))
		data->player.rotate = 1;
}

static void	release_key(mlx_key_data_t keydata, t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)
		&& keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		data->player.w_s = 1;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE
		&& mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->player.w_s = -1;
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		&& keydata.action == MLX_RELEASE)
		data->player.w_s = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)
		&& (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE))
		data->player.a_d = 1;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE
		&& mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->player.a_d = -1;
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		&& keydata.action == MLX_RELEASE)
		data->player.a_d = 0;
	if ((keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_E)
		&& keydata.action == MLX_RELEASE)
		data->player.rotate = 0;
	else if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_RELEASE)
		data->player.rotate = 0;
}

void	ft_keys(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	w_s_func(keydata, data);
	a_d_func(keydata, data);
	rotate_func(keydata, data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	release_key(keydata, data);
}
