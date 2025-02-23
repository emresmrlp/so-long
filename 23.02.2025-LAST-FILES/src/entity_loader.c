/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:32:20 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/22 15:42:18 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	parse_entity(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == 'P')
	{
		data->map.p_count++;
		data->entity.player_x = x;
		data->entity.player_y = y;
	}
	else if (data->map.map[y][x] == 'C')
		data->map.c_count++;
	else if (data->map.map[y][x] == 'E')
	{
		data->map.x_count++;
		data->entity.exit_x = x;
		data->entity.exit_y = y;
	}
	else if (data->map.map[y][x] != '1' && data->map.map[y][x] != '0')
		return (error_handler(ERROR_MAP_INV_CONTAINS));
	return (0);
}

int	entity_load(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map.map[y] != NULL)
	{
		x = 0;
		while (data->map.map[y][x] != '\0')
		{
			if (parse_entity(data, x, y))
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
