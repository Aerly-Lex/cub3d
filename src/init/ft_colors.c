/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:11:59 by Dscheffn          #+#    #+#             */
/*   Updated: 2024/05/05 12:45:10 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	rgba_to_hex(int r, int g, int b, int a)
{
	unsigned int	hex_color;

	hex_color = 0;
	hex_color |= (r & 0xFF) << 24;
	hex_color |= (g & 0xFF) << 16;
	hex_color |= (b & 0xFF) << 8;
	hex_color |= (a & 0xFF);
	return (hex_color);
}

static int	parse_number(char *str, int *i)
{
	int	value;

	value = ft_atoi(&str[*i]);
	while (str[*i] && str[*i] != ',')
		(*i)++;
	if (str[*i] == ',')
		(*i)++;
	return (value);
}

void	load_colors(t_map *map)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	r = parse_number(map->textures[4], &i);
	g = parse_number(map->textures[4], &i);
	b = parse_number(map->textures[4], &i);
	map->floor_color = rgba_to_hex(r, g, b, 255);
	i = 0;
	r = parse_number(map->textures[5], &i);
	g = parse_number(map->textures[5], &i);
	b = parse_number(map->textures[5], &i);
	map->ceiling_color = rgba_to_hex(r, g, b, 255);
}
