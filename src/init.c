/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:23:53 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/09 12:16:09 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/error.h"

int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (error_handler(ERROR_MINILIBX_INIT));
	data->win = mlx_new_window(data->mlx, data->map.size_x * 64,
			data->map.size_y * 64, "so_long");
	if (!data->win)
		return (error_handler(ERROR_WINDOW_INIT));
	parse_keys(data);
	return (0);
}

int	init_textures(t_data *data)
{
	parse_map_textures(data);
	parse_player_textures(data);
	parse_extra_textures(data);
	return (0);
}

int	init_map(t_data *data, char *map_path)
{
	if (check_file_valid_path(map_path))
		return (1);
	if (parse_map(data, map_path))
		return (1);
	if (check_map(data))
		return (1);
	return (0);
}

int	init_entities(t_data *data)
{
	int	i;

	mlx_put_image_to_window(data->mlx, data->win, data->image.player_down,
		data->entity.player_x * 64, data->entity.player_y * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->image.exit,
		data->entity.exit_x * 64, data->entity.exit_y * 64);
	if (parse_collectibles(data))
		return (1);
	i = 0;
	while (i < data->map.c_count)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->image.collectible,
			data->entity.coll[i][0] * 64,
			data->entity.coll[i][1] * 64);
		i++;
	}
	return (0);
}
