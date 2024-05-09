/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:10:39 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/05/09 15:33:10 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_wall(t_data *data, double x, double y)
{
	int	x_map;
	int	y_map;

	if (x < 0 || y < 0)
		return (1);
	x_map = floor(x / TILE);
	y_map = floor(y / TILE);
	if (y_map > data->map->m_height || x_map > data->map->m_width)
		return (1);
	if (data->map->map2d[y_map]
		&& x_map <= (int)ft_strlen(data->map->map2d[y_map]))
		if (data->map->map2d[y_map][x_map] == '1')
			return (1);
	return (0);
}

// Calculate the distance using pythagoras a^2 + b^2 = c^2
// and take the closest distance
static double	calc_distance(double x1, double x2, double y1, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

//	DDA Distance calculation from Player position till inter/wall
static double	calc_horiz(t_data *data, double angle)
{
	double	x;
	double	y;
	double	x_step;
	double	y_step;
	int		pixel;

	y_step = TILE;
	x_step = TILE / tan(angle);
	y = floor(data->player.player_y / TILE) * TILE;
	pixel = inter_check(angle, &y, &y_step, 1);
	x = data->player.player_x + (y - data->player.player_y) / tan(angle);
	if ((unit_circle(angle, 'y') && x_step > 0)
		|| (!unit_circle(angle, 'y') && x_step < 0))
		x_step *= -1;
	while (!check_wall(data, x, y - pixel))
	{
		x += x_step;
		y += y_step;
	}
	data->ray.wall_hit_x = x;
	return (calc_distance(data->player.player_x, x, data->player.player_y, y));
}

// DDA
static double	calc_vertic(t_data *data, double angle)
{
	double	x;
	double	y;
	double	x_step;
	double	y_step;
	int		pixel;

	x_step = TILE;
	y_step = TILE * tan(angle);
	x = floor(data->player.player_x / TILE) * TILE;
	pixel = inter_check(angle, &x, &x_step, 0);
	y = data->player.player_y + (x - data->player.player_x) * tan(angle);
	if ((unit_circle(angle, 'x') && y_step < 0)
		|| (!unit_circle(angle, 'x') && y_step > 0))
		y_step *= -1;
	while (!check_wall(data, x - pixel, y))
	{
		x += x_step;
		y += y_step;
	}
	data->ray.wall_hit_y = y;
	return (calc_distance(data->player.player_x, x, data->player.player_y, y));
}

void	raycast(t_data *data)
{
	double	horiz;
	double	vertic;
	int		ray;

	ray = -1;
	data->ray.r_angle = data->player.p_angle - data->player.fov_rad / 2;
	while (++ray < WIDTH)
	{
		horiz = calc_horiz(data, normalize_angle(data->ray.r_angle));
		vertic = calc_vertic(data, normalize_angle(data->ray.r_angle));
		data->ray.horiz_x = horiz;
		data->ray.vertic_y = vertic;
		if (vertic <= horiz)
		{
			data->ray.distance = vertic;
			data->ray.flag = 0;
		}
		else
		{
			data->ray.distance = horiz;
			data->ray.flag = 1;
		}
		render(data, ray, data->ray.distance);
		data->ray.r_angle += data->player.fov_rad / WIDTH;
	}
}
