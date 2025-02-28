/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:24:29 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/27 19:13:32 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	apply_wall_and_floor_textures(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map.map[y] != NULL)
	{
		x = 0;
		while (data->map.map[y][x] != '\0')
		{
			if (data->map.map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win,
					data->image.wall, x * 64, y * 64);
			else
				mlx_put_image_to_window(data->mlx, data->win,
					data->image.floor, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
