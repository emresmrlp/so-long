/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:56:27 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/09 09:42:10 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/error.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

static int	path_checker(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.size_y)
	{
		x = 0;
		while (x < data->map.size_x)
		{
			if (data->map.copy[y][x] == 'X' || data->map.copy[y][x] == 'C')
				return (error_handler(ERROR_MAP_NO_VALID_PATH));
			x++;
		}
		y++;
	}
	return (0);
}

int	check_valid_path(t_data *data)
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
		{
			free_copy_map(data);
			return (error_handler(ERROR_MAP_ALLOCATION));
		}
		ft_strlcpy(data->map.copy[i], data->map.map[i],
			data->map.size_x + 1);
		i++;
	}
	data->map.copy[i] = NULL;
	flood_fill(data, data->entity.player_x, data->entity.player_y);
	if (path_checker(data))
		return (1);
	free_copy_map(data);
	return (0);
}
