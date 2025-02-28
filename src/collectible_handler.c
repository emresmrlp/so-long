/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:00:08 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/27 19:13:22 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	collectible_collect(t_data *data, int i)
{
	data->entity.coll[i][0] = -1;
	data->entity.coll[i][1] = -1;
	data->map.collected_c_count++;
	if (data->map.collected_c_count == data->map.c_count)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->image.exit_open,
			data->entity.exit_x * 64, data->entity.exit_y * 64);
		ft_printf("(0,0) You did it! Now run to the exit!\n");
	}
}

static int	collectible_allocate(t_data *data, int *i, int x, int y)
{
	data->entity.coll[*i] = (int *)ft_calloc(2, sizeof(int));
	if (!data->entity.coll[*i])
		error_handler(ERROR_COLLECT_ALLOCATION);
	data->entity.coll[*i][0] = x;
	data->entity.coll[*i][1] = y;
	(*i)++;
	return (0);
}

void	collecitble_check(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	while (i < data->map.c_count)
	{
		if (data->entity.coll[i][0] == x && data->entity.coll[i][1] == y)
			collectible_collect(data, i);
		i++;
	}
}

int	collectible_load(t_data *data)
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
				if (collectible_allocate(data, &i, x, y))
					return (1);
			}
			x++;
		}
		y++;
	}
	data->entity.coll[i] = NULL;
	return (0);
}
