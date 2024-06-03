/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 10:54:09 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/05/10 14:01:58 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_data *data, int ray, int top)
{
	int	i;

	i = 0;
	while (i < top)
		mlx_put_pixel(data->window, ray, i++, data->map->ceiling_color);
}

void	draw_floor(t_data *data, int ray, int bot)
{
	int	i;

	i = bot;
	while (i < HEIGHT)
		mlx_put_pixel(data->window, ray, i++, data->map->floor_color);
}

void	render(t_data *data, int ray, double distance)
{
	double	wall_height;
	double	top;
	double	bot;

	distance *= cos(normalize_angle(data->ray.r_angle - data->player.p_angle));
	wall_height = TILE / distance * (WIDTH / 2);
	top = (HEIGHT / 2) - (wall_height / 2);
	bot = (HEIGHT / 2) + (wall_height / 2);
	draw_ceiling(data, ray, top);
	draw_floor(data, ray, bot);
	draw_wall(data, ray, top, bot);
}
