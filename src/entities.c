/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:00:08 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/07 20:02:38 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/error.h"

void	check_collectible(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	while (i < data->map.c_count)
	{
		if (data->entity.coll[i][0] == x && data->entity.coll[i][1] == y)
		{
			data->entity.coll[i][0] = -1;
			data->entity.coll[i][1] = -1;
			data->map.collected_c_count++;
		}
		i++;
	}
}

static int	allocate_collectible(t_data *data, int *i, int x, int y)
{
	data->entity.coll[*i] = (int *)ft_calloc(2, sizeof(int));
	if (!data->entity.coll[*i])
		error_handler(ERROR_COLLECT_ALLOCATION);
	data->entity.coll[*i][0] = x;
	data->entity.coll[*i][1] = y;
	(*i)++;
	return (0);
}

int	parse_collectibles(t_data *data)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	i = 0;
	data->entity.coll = (int **)ft_calloc(data->map.c_count + 1, sizeof(int *));
	if (!data->entity.coll)
		error_handler(ERROR_COLLECT_ALLOCATION);
	while (data->map.map[y] != NULL)
	{
		x = 0;
		while (data->map.map[y][x] != '\0')
		{
			if (data->map.map[y][x] == 'C' && i < data->map.c_count)
			{
				if (allocate_collectible(data, &i, x, y))
					return (1);
			}
			x++;
		}
		y++;
	}
	data->entity.coll[i] = NULL;
	return (0);
}
