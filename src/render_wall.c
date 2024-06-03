/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:55:16 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/05/10 14:05:00 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static int	get_pixel_color(mlx_image_t *texture, int x, int y)
{
	unsigned int	i;

	i = (y * texture->width + x) * 4;
	return (get_rgba(texture->pixels[i], texture->pixels[i + 1],
			texture->pixels[i + 2], texture->pixels[i + 3]));
}

// Determine which texture to load depending on the view-/ray-angle
static void	get_texture(t_data *data)
{
	double	angle;

	angle = normalize_angle(data->ray.r_angle);
	if (data->ray.flag == 0)
	{
		if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
			data->f_tex = WEST;
		else
			data->f_tex = EAST;
	}
	else
	{
		if (angle > 0 && angle < M_PI)
			data->f_tex = SOUTH;
		else
			data->f_tex = NORTH;
	}
}

// calculate_texture_x (thanks norminette!)
static int	c_tex_x(t_data *data, int texture_width)
{
	double	relative_pos;
	int		texture_x;

	if (data->ray.flag == 0)
		relative_pos = fmod(data->ray.wall_hit_y, TILE);
	else
		relative_pos = fmod(data->ray.wall_hit_x, TILE);
	texture_x = (int)(relative_pos / TILE * texture_width);
	if (data->f_tex == WEST || data->f_tex == SOUTH)
		texture_x = texture_width - texture_x - 1;
	return (texture_x);
}

void	draw_wall(t_data *data, int ray, int top, int bot)
{
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;

	get_texture(data);
	step = (double)data->tex[data->f_tex]->height / (bot - top);
	tex_x = c_tex_x(data, data->tex[data->f_tex]->width);
	if ((bot - top) > HEIGHT)
		tex_y = top - (HEIGHT / 2) + ((bot - top) / 2) * step;
	else
		tex_y = HEIGHT;
	tex_pos = 0;
	while (top < bot && top < HEIGHT)
	{
		tex_y = (int)tex_pos % data->tex[data->f_tex]->height;
		tex_pos += step;
		if (top < 0)
		{
			top++;
			continue ;
		}
		mlx_put_pixel(data->window, ray, top++,
			get_pixel_color(data->tex[data->f_tex], tex_x, tex_y));
	}
}

	// if (data->ray.wall_hit_x < 0)
	// 	return ;

// if (ray < 20 )
// 	printf("%d step:%f top:%d bot:%d tex_x:%d tex_y:%d\n",
// ray, step, top, bot, tex_x, tex_y);

// 0 step:1.241877 top:-14 bot:1094 tex_x:374 tex_y:134
// 0 step:0.938608 top:-193 bot:1273 tex_x:67 tex_y:-45
