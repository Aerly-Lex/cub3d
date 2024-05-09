/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:08:20 by ajakob            #+#    #+#             */
/*   Updated: 2024/05/05 15:25:57 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*create_path(t_data *data, char *element, int *y, int *x)
{
	char	**file;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = *x;
	file = data->map->file;
	while (file[*y][*x] && !(file[*y][*x] == ' ' ||
		file[*y][*x] == '\t' || file[*y][*x] == '\n'))
	{
		(*x)++;
		i++;
	}
	str = ft_calloc(sizeof(char), i + 1);
	if (!str)
		ft_error(data, "Allocation Failed\n");
	ft_strlcpy(str, &file[*y][j], i + 1);
	check_path(data, str, element[0]);
	return (str);
}

static void	check_for_doubles(t_data *data, char **textures)
{
	char	str[7];
	int		i;
	int		j;
	int		k;

	ft_strlcpy(str, "NSWEFC", 7);
	i = 0;
	while (str[i])
	{
		j = 0;
		k = 0;
		while (j < 12)
		{
			if (textures[j] && textures[j][0] == str[i])
				k++;
			if (k > 1)
				ft_error(data, "Found doubles\n");
			j += 2;
		}
		i++;
	}
}

static void	sorting(char **tmp, char **textures, int i)
{
	if (textures[i][0] == 'N')
		tmp[0] = ft_strdup(textures[i + 1]);
	else if (textures[i][0] == 'S')
		tmp[1] = ft_strdup(textures[i + 1]);
	else if (textures[i][0] == 'W')
		tmp[2] = ft_strdup(textures[i + 1]);
	else if (textures[i][0] == 'E')
		tmp[3] = ft_strdup(textures[i + 1]);
	else if (textures[i][0] == 'F')
		tmp[4] = ft_strdup(textures[i + 1]);
	else if (textures[i][0] == 'C')
		tmp[5] = ft_strdup(textures[i + 1]);
}

static char	**sort_order(t_data *data, char **textures)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	tmp = ft_calloc(sizeof(char *), 7);
	if (!tmp)
		ft_error(data, "Allocation Failed\n");
	tmp[6] = NULL;
	while (textures[i])
	{
		sorting(tmp, textures, i);
		i += 2;
	}
	free_double_ptr(textures);
	return (tmp);
}

char	**ft_create_textures(t_data *data)
{
	char	**textures;
	int		i;
	int		y;
	int		x;

	textures = ft_calloc(sizeof(char *), 13);
	if (!textures)
		ft_error(data, "Allocation Failed\n");
	textures[12] = NULL;
	i = 0;
	y = 0;
	x = 0;
	while (i < 12)
	{
		skip_spaces(data->map->file, &y, &x);
		textures[i++] = check_elements(data, &y, &x);
		skip_spaces(data->map->file, &y, &x);
		textures[i] = create_path(data, textures[i - 1], &y, &x);
		i++;
	}
	check_for_doubles(data, textures);
	textures = sort_order(data, textures);
	skip_spaces(data->map->file, &y, &x);
	realloc_file(data, data->map->file, y);
	return (textures);
}
