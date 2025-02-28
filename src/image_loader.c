/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:38:37 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/27 19:13:34 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	add_new_texture(t_data *data, char *path, void **texture)
{
	t_image	sprite;

	sprite.xpm = mlx_xpm_file_to_image(data->mlx, path,
			&data->image.img_width, &data->image.img_height);
	*texture = (void *)sprite.xpm;
}

static int	load_map_textures(t_data *data)
{
	add_new_texture(data, "./textures/wall.xpm", &data->image.wall);
	if (!data->image.wall)
		return (error_handler(ERROR_TEXTURE_INIT));
	add_new_texture(data, "./textures/floor.xpm", &data->image.floor);
	if (!data->image.floor)
		return (error_handler(ERROR_TEXTURE_INIT));
	add_new_texture(data, "./textures/exit.xpm", &data->image.exit);
	if (!data->image.exit)
		return (error_handler(ERROR_TEXTURE_INIT));
	add_new_texture(data, "./textures/collectible.xpm",
		&data->image.collectible);
	if (!data->image.collectible)
		return (error_handler(ERROR_TEXTURE_INIT));
	add_new_texture(data, "./textures/exit_player.xpm",
		&data->image.exit_player);
	if (!data->image.exit_player)
		return (error_handler(ERROR_TEXTURE_INIT));
	add_new_texture(data, "./textures/exit_open.xpm",
		&data->image.exit_open);
	if (!data->image.exit_open)
		return (error_handler(ERROR_TEXTURE_INIT));
	return (0);
}

static int	load_player_textures(t_data *data)
{
	add_new_texture(data, "./textures/player_down.xpm",
		&data->image.player_down);
	if (!data->image.player_down)
		return (error_handler(ERROR_TEXTURE_INIT));
	add_new_texture(data, "./textures/player_left.xpm",
		&data->image.player_left);
	if (!data->image.player_left)
		return (error_handler(ERROR_TEXTURE_INIT));
	add_new_texture(data, "./textures/player_right.xpm",
		&data->image.player_right);
	if (!data->image.player_right)
		return (error_handler(ERROR_TEXTURE_INIT));
	add_new_texture(data, "./textures/player_up.xpm",
		&data->image.player_up);
	if (!data->image.player_up)
		return (error_handler(ERROR_TEXTURE_INIT));
	return (0);
}

int	load_textures(t_data *data)
{
	if (load_player_textures(data))
		return (1);
	if (load_map_textures(data))
		return (1);
	return (0);
}
