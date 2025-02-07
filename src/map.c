/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:19:18 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/07 19:20:04 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/error.h"

int	check_file_valid_path(char *map_path)
{
	char	*extension;

	extension = ft_strrchr(map_path, '.');
	if (!extension || ft_strncmp(extension, ".ber", 5) != 0)
		return (error_handler(ERROR_INVALID_FILE));
	return (0);
}

static int	check_entities(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == 'P')
	{
		data->map.p_count++;
		data->entity.player_x = x;
		data->entity.player_y = y;
	}
	else if (data->map.map[y][x] == 'C')
		data->map.c_count++;
	else if (data->map.map[y][x] == 'X')
	{
		data->map.x_count++;
		data->entity.exit_x = x;
		data->entity.exit_y = y;
	}
	else if (data->map.map[y][x] != '1' && data->map.map[y][x] != '0')
		return (error_handler(ERROR_MAP_INV_CONTAINS));
	return (0);
}

static int	validate_entities(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map.map[y] != NULL)
	{
		x = 0;
		while (data->map.map[y][x] != '\0')
		{
			if (check_entities(data, x, y))
				return (1);
			x++;
		}
		y++;
	}
	if (data->map.p_count != 1 || data->map.x_count != 1
		|| data->map.c_count < 1)
		return (error_handler(ERROR_MAP_ENTITY));
	return (0);
}

static int	is_map_closed(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.size_y && data->map.map[i] != NULL)
	{
		j = 0;
		if (!data->map.map || i >= data->map.size_y || j >= data->map.size_x)
			return (error_handler(ERROR_MAP_WALLS));
		if (i == 0 || i == data->map.size_y - 1)
		{
			while (j < data->map.size_x && data->map.map[i][j] != '\0')
			{
				if (data->map.map[i][j] != '1')
					return (error_handler(ERROR_MAP_WALLS));
				j++;
			}
		}
		if (data->map.map[i][0] != '1'
			|| data->map.map[i][data->map.size_x - 1] != '1')
			return (error_handler(ERROR_MAP_WALLS));
		i++;
	}
	return (0);
}

int	check_map(t_data *data)
{
	if (data->map.size_x == data->map.size_y)
		return (error_handler(ERROR_MAP_MUST_RECTANGULAR));
	if (data->map.size_x < 3 || data->map.size_y < 3)
		return (error_handler(ERROR_MAP_NO_VALID_PATH));
	if (is_map_closed(data))
		return (1);
	if (validate_entities(data))
		return (1);
	return (0);
}
