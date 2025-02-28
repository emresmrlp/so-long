/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:34:51 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/27 19:14:02 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map.size_x
		|| y >= data->map.size_y)
		return ;
	if (data->map.copy[y][x] == '1' || data->map.copy[y][x] == 'o')
		return ;
	data->map.copy[y][x] = 'o';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}

static int	map_copy_create(t_data *data)
{
	int	i;

	data->map.copy = (char **)ft_calloc(data->map.size_y + 1, sizeof(char *));
	if (!data->map.copy)
		return (error_handler(ERROR_MAP_ALLOCATION));
	i = 0;
	while (i < data->map.size_y)
	{
		data->map.copy[i]
			= (char *)ft_calloc(data->map.size_x + 1, sizeof(char));
		if (!data->map.copy[i])
			return (error_handler(ERROR_MAP_ALLOCATION));
		ft_strlcpy(data->map.copy[i], data->map.map[i],
			data->map.size_x + 1);
		i++;
	}
	data->map.copy[i] = NULL;
	return (0);
}

static int	map_copy_check(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.size_y)
	{
		x = 0;
		while (x < data->map.size_x)
		{
			if (data->map.copy[y][x] == 'E' || data->map.copy[y][x] == 'C')
				return (error_handler(ERROR_MAP_NO_VALID_PATH));
			x++;
		}
		y++;
	}
	return (0);
}

static void	map_copy_cleanup(t_data *data)
{
	int	i;

	i = data->map.size_y;
	if (data->map.copy)
	{
		while (i--)
		{
			if (data->map.copy[i])
			{
				free(data->map.copy[i]);
				data->map.copy[i] = NULL;
			}
		}
		free(data->map.copy);
		data->map.copy = NULL;
	}
}

int	can_play_map(t_data *data)
{
	if (map_copy_create(data))
		return (1);
	flood_fill(data, data->entity.player_x, data->entity.player_y);
	if (map_copy_check(data))
		return (1);
	map_copy_cleanup(data);
	return (0);
}
