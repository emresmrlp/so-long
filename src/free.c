/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:55:29 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/07 20:01:55 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_map(t_data *data)
{
	if (data->map.map)
	{
		while (data->map.map[data->map.size_y--])
		{
			if (data->map.map[data->map.size_y])
			{
				free(data->map.map[data->map.size_y]);
				data->map.map[data->map.size_y] = NULL;
			}
		}
		free(data->map.map);
		data->map.map = NULL;
	}
}

static void	free_collectibles(t_data *data)
{
	int	i;

	i = 0;
	if (data->entity.coll)
	{
		while (i < data->map.c_count)
		{
			if (data->entity.coll[i])
			{
				free(data->entity.coll[i]);
				data->entity.coll[i] = NULL;
			}
			i++;
		}
		free(data->entity.coll);
		data->entity.coll = NULL;
	}
}

void	free_copy_map(t_data *data)
{
	if (data->map.copy)
	{
		while (data->map.copy[data->map.size_y--])
		{
			if (data->map.copy[data->map.size_y])
			{
				free(data->map.copy[data->map.size_y]);
				data->map.copy[data->map.size_y] = NULL;
			}
		}
		free(data->map.copy);
		data->map.copy = NULL;
	}
}

int	free_all(t_data *data)
{
	if (data)
	{
		free_map(data);
		free_copy_map(data);
		free_collectibles(data);
		free(data);
		data = NULL;
	}
	return (1);
}
