/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:19:18 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/27 19:13:49 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_map_file_extension(char *map_path)
{
	char	*extension;

	extension = ft_strrchr(map_path, '.');
	if (!extension || ft_strncmp(extension, ".ber", 5) != 0)
		return (error_handler(ERROR_INVALID_FILE));
	if (*(extension - 1) == '/')
		return (error_handler(ERROR_INVALID_FILE));
	return (0);
}

static int	check_map_walls(t_data *data, int y)
{
	int	x;

	x = 0;
	if (y == 0 || y == data->map.size_y - 1)
	{
		while (x < data->map.size_x && data->map.map[y][x] != '\0')
		{
			if (data->map.map[y][x] != '1')
				return (error_handler(ERROR_MAP_WALLS));
			x++;
		}
	}
	if (data->map.map[y][0] != '1'
		|| data->map.map[y][data->map.size_x - 1] != '1')
		return (error_handler(ERROR_MAP_WALLS));
	return (0);
}

static int	check_map(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->map.size_y && data->map.map[y] != NULL)
	{
		if (!data->map.map || y >= data->map.size_y)
			return (error_handler(ERROR_MAP_WALLS));
		if (check_map_walls(data, y))
			return (1);
		y++;
	}
	return (0);
}

int	validate_map(t_data *data, char *map_path)
{
	if (check_map_file_extension(map_path))
		return (1);
	if (load_map(data, map_path))
		return (1);
	if (data->map.size_x < 3 || data->map.size_y < 3)
		return (error_handler(ERROR_INVALID_MAP));
	if (check_map(data))
		return (1);
	if (entity_load(data))
		return (1);
	if (can_play_map(data))
		return (1);
	return (0);
}
