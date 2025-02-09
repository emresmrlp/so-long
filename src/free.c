/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:55:29 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/09 11:40:42 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_map(t_data *data)
{
	int	i;

	i = data->map.size_y;
	if (data->map.map)
	{
		while (i--)
		{
			if (data->map.map[i])
			{
				free(data->map.map[i]);
				data->map.map[i] = NULL;
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
