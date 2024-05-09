/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Dscheffn <dscheffn@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:14:34 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/05/09 16:01:28 by Dscheffn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "MLX42/MLX42.h"

# define HEIGHT	1080
# define WIDTH	1920
# define FOV	60
# define TILE	10
# define MV_SPEED 2
# define ROTATION_SPEED 0.05

# define BLACK       0x000000FF  // RGB(0, 0, 0)
# define WHITE       0xFFFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000FF  // RGB(255, 0, 0)
# define GREEN       0x00FF00FF  // RGB(0, 255, 0)
# define BLUE        0x0000FFFF  // RGB(0, 0, 255)
# define YELLOW      0xFFFF00FF  // RGB(255, 255, 0)
# define CYAN        0x00FFFFFF  // RGB(0, 255, 255)
# define PURPLE      0x800080FF  // RGB(128, 0, 128)
# define ORANGE      0xFFA500FF  // RGB(255, 165, 0)
# define BROWN       0x8B4513FF  // RGB(165, 42, 42)

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define DIRECTION_COUNT 4

typedef struct s_map {
	int		ceiling_color;
	int		floor_color;
	char	**file;
	char	**textures;
	char	**map2d;
	char	direction;
	int		x_player;
	int		y_player;
	int		m_width;
	int		m_height;
}	t_map;

typedef struct s_player {
	int		player_x;
	int		player_y;
	double	p_angle;
	float	fov_rad;
	int		a_d;
	int		w_s;
	double	mv_y;
	double	mv_x;
	int		rotate;
}	t_player;

typedef struct s_ray {
	double	r_angle;
	double	distance;
	double	horiz_x;
	double	vertic_y;
	double	wall_hit_x;
	double	wall_hit_y;
	int		flag;
}	t_ray;

typedef struct s_data {
	mlx_t			*mlx;
	mlx_image_t		*window;
	mlx_image_t		*tex[DIRECTION_COUNT];
	t_map			*map;
	int				f_tex;
	t_player		player;
	t_ray			ray;
}	t_data;

// ft_error.c
void	ft_error(t_data *data, char *str);
void	liberator(t_data *data);

// ft_hook.c
void	ft_hooks(t_data *data);

// ft_key.c
void	ft_keys(mlx_key_data_t keydata, void *param);

// ft_raycast_utils.c
double	normalize_angle(double angle);
int		unit_circle(float angle, char c);
int		inter_check(double angle, double *inter, double *step, int is_horizon);

// ft_raycast.c
void	raycast(t_data *data);

// render.c
void	render(t_data *data, int ray, double distance);

// render_wall.c
void	draw_wall(t_data *data, int ray, int top, int bot);

/////////////////// INIT ///////////////////

// ft_init_utils.c
int		ft_map_size(char *argv);
void	free_double_ptr(char **ptr);
void	r_skip_spaces(char **file, int *y, int *x);
void	skip_spaces(char **file, int *y, int *x);
void	werror_ignore_free(char *str);

// ft_colors.c
void	load_colors(t_map *map);

// ft_textures_load.c
void	load_textures(t_map *map, t_data *data);

// ft_flood_fill.c
void	check_flood_fill(t_data *data, char **file);

// ft_init_map.c
void	ft_init_map(t_data *data, int argc, char **argv);

//ft_map2d.c
char	**ft_create_map2d(t_data *data);

// ft_realloc_file.c
void	realloc_file(t_data *data, char **file, int y);

// ft_texture_utils.c
char	*check_elements(t_data *data, int *y, int *x);
void	check_path(t_data *data, char *str, char element);

// ft_texture.c
void	skip_spaces(char **file, int *y, int *x);
void	ft_create_textures(t_data *data);

//https://www.omnicalculator.com/math/circle
#endif