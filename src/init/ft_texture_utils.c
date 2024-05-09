/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:25:21 by ajakob            #+#    #+#             */
/*   Updated: 2024/05/05 14:15:25 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*element_util(t_data *data, char *file, int *x, int num)
{
	char	*str;

	if (file[*x + num] != '\t' && file[*x + num] != ' '
		&& file[*x + num] != '\n')
		ft_error(data, "Invalid element name\n");
	str = ft_calloc(sizeof(char), num + 1);
	if (!str)
		ft_error(data, "Allocation Failed\n");
	ft_strlcpy(str, &file[*x], (num + 1));
	return (str);
}

char	*check_elements(t_data *data, int *y, int *x)
{
	char	**file;
	char	*str;

	file = data->map->file;
	str = NULL;
	if ((file[*y][*x] == 'N' && file[*y][*x + 1] == 'O')
		|| (file[*y][*x] == 'S' && file[*y][*x + 1] == 'O')
		|| (file[*y][*x] == 'E' && file[*y][*x + 1] == 'A')
		|| (file[*y][*x] == 'W' && file[*y][*x + 1] == 'E'))
	{
		str = element_util(data, file[*y], x, 2);
		*x += 2;
	}
	else if (file[*y][*x] == 'F' || file[*y][*x] == 'C')
	{
		str = element_util(data, file[*y], x, 1);
		(*x)++;
	}
	else
		ft_error(data, "Invalid element name\n");
	return (str);
}

static void	count_comma(t_data *data, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ',' && (str[i] < '0' || str[i] > '9'))
			ft_error(data, "Invalid color text\n");
		if (str[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		ft_error(data, "Invalid amount of \',\'\n");
}

static void	check_valid_num(t_data *data, char *str)
{
	char	**num;
	int		i;

	i = 0;
	count_comma(data, str);
	num = ft_split(str, ',');
	if (!num)
		ft_error(data, "Allocation Failed\n");
	while (num[i] && i < 3)
	{
		if (ft_atoi(num[i]) < 0 || ft_atoi(num[i]) > 255)
		{
			free(str);
			free_double_ptr(num);
			ft_error(data, "Invalid color number\n");
		}
		i++;
	}
	if (num[i] || i != 3)
	{
		free(str);
		free_double_ptr(num);
		ft_error(data, "Invalid amount of color numbers\n");
	}
	free_double_ptr(num);
}

void	check_path(t_data *data, char *str, char element)
{
	int	fd;

	if (!(element == 'F' || element == 'C'))
	{
		fd = open(str, O_RDONLY);
		if (fd == -1)
		{
			free(str);
			ft_error(data, "Invalid path\n");
		}
		close(fd);
	}
	else
		check_valid_num(data, str);
}
