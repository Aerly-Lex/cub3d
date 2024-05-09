/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:59:00 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/05/07 12:12:21 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mv_player(t_data *data, double mv_y, double mv_x)
{
	int		new_y;
	int		new_x;

	new_y = roundf(data->player.player_y + mv_y);
	new_x = roundf(data->player.player_x + mv_x);
	if (new_y / TILE > 0 && new_x / TILE > 0
		&& new_y / TILE < data->map->m_height
		&& new_x / TILE < data->map->m_width
		&& data->map->map2d[new_y / TILE][new_x / TILE] != '1'
		&& data->map->map2d[new_y / TILE][(new_x - 1) / TILE] != '1'
		&& data->map->map2d[(new_y - 1) / TILE][new_x / TILE] != '1')
	{
		data->player.player_y = new_y;
		data->player.player_x = new_x;
	}
}

static void	rotate_player(t_data *data, int i)
{
	if (i == -1)
	{
		data->player.p_angle -= ROTATION_SPEED;
		if (data->player.p_angle < 0)
			data->player.p_angle += 2 * M_PI;
	}
	else
	{
		data->player.p_angle += ROTATION_SPEED;
		if (data->player.p_angle > 2 * M_PI)
			data->player.p_angle -= 2 * M_PI;
	}
}

static void	w_s_a_d(t_data *data)
{
	if (data->player.w_s == 1)
	{
		data->player.mv_y = sin(data->player.p_angle) * MV_SPEED;
		data->player.mv_x = cos(data->player.p_angle) * MV_SPEED;
		mv_player(data, data->player.mv_y, data->player.mv_x);
	}
	if (data->player.w_s == -1)
	{
		data->player.mv_y = -sin(data->player.p_angle) * MV_SPEED;
		data->player.mv_x = -cos(data->player.p_angle) * MV_SPEED;
		mv_player(data, data->player.mv_y, data->player.mv_x);
	}
	if (data->player.a_d == 1)
	{
		data->player.mv_y = -cos(data->player.p_angle) * MV_SPEED;
		data->player.mv_x = sin(data->player.p_angle) * MV_SPEED;
		mv_player(data, data->player.mv_y, data->player.mv_x);
	}
	if (data->player.a_d == -1)
	{
		data->player.mv_y = cos(data->player.p_angle) * MV_SPEED;
		data->player.mv_x = -sin(data->player.p_angle) * MV_SPEED;
		mv_player(data, data->player.mv_y, data->player.mv_x);
	}
}

// UNDER CONSTRUCTION
// void	ft_cursor(mlx_t* mlx, mlx_cursorfunc func, void* param)
// {
// 	t_env	*data;

// 	data = (t_env *)param;
// }

void	ft_hooks(t_data *data)
{
	w_s_a_d(data);
	if (data->player.rotate == 1)
		rotate_player(data, 1);
	if (data->player.rotate == -1)
		rotate_player(data, -1);
}
