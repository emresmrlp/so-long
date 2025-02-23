/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:24:29 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/22 16:37:36 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	image_cleanup(t_data *data)
{
	mlx_destroy_image(data->mlx, data->image.wall);
	mlx_destroy_image(data->mlx, data->image.floor);
	mlx_destroy_image(data->mlx, data->image.exit);
	mlx_destroy_image(data->mlx, data->image.exit_player);
	mlx_destroy_image(data->mlx, data->image.collectible);
	mlx_destroy_image(data->mlx, data->image.player_down);
	mlx_destroy_image(data->mlx, data->image.player_left);
	mlx_destroy_image(data->mlx, data->image.player_right);
	mlx_destroy_image(data->mlx, data->image.player_up);
}

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
