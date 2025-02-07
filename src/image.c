/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:24:29 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/07 19:53:32 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/error.h"

int	parse_map_textures(t_data *data)
{
	data->image.wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall.xpm",
			&data->image.img_width, &data->image.img_height);
	if (!data->image.wall)
		return (error_handler(ERROR_TEXTURE_INIT));
	data->image.floor = mlx_xpm_file_to_image(data->mlx,
			"./textures/floor.xpm",
			&data->image.img_width, &data->image.img_height);
	if (!data->image.floor)
		return (error_handler(ERROR_TEXTURE_INIT));
	data->image.exit = mlx_xpm_file_to_image(data->mlx,
			"./textures/exit.xpm",
			&data->image.img_width, &data->image.img_height);
	if (!data->image.exit)
		return (error_handler(ERROR_TEXTURE_INIT));
	data->image.collectible = mlx_xpm_file_to_image(data->mlx,
			"./textures/collectible.xpm",
			&data->image.img_width, &data->image.img_height);
	if (!data->image.collectible)
		return (error_handler(ERROR_TEXTURE_INIT));
	return (0);
}

int	parse_player_textures(t_data *data)
{
	data->image.player_down = mlx_xpm_file_to_image(data->mlx,
			"./textures/player_down.xpm",
			&data->image.img_width, &data->image.img_height);
	if (!data->image.player_down)
		return (error_handler(ERROR_TEXTURE_INIT));
	data->image.player_left = mlx_xpm_file_to_image(data->mlx,
			"./textures/player_left.xpm",
			&data->image.img_width, &data->image.img_height);
	if (!data->image.player_left)
		return (error_handler(ERROR_TEXTURE_INIT));
	data->image.player_right = mlx_xpm_file_to_image(data->mlx,
			"./textures/player_right.xpm",
			&data->image.img_width, &data->image.img_height);
	if (!data->image.player_right)
		return (error_handler(ERROR_TEXTURE_INIT));
	data->image.player_up = mlx_xpm_file_to_image(data->mlx,
			"./textures/player_up.xpm", &data->image.img_width,
			&data->image.img_height);
	if (!data->image.player_up)
		return (error_handler(ERROR_TEXTURE_INIT));
	return (0);
}

void	put_background(t_data *data)
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
