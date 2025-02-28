/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:23:53 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/27 19:13:27 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (error_handler(ERROR_MINILIBX_INIT));
	if (load_textures(data))
		return (1);
	data->win = mlx_new_window(data->mlx, data->map.size_x * 64,
			data->map.size_y * 64, "so_long by ysumeral");
	if (!data->win)
		return (error_handler(ERROR_WINDOW_INIT));
	register_input_hooks(data);
	return (0);
}

static int	init_map(t_data *data, char *map_path)
{
	if (validate_map(data, map_path))
		return (1);
	return (0);
}

static int	init_entities(t_data *data)
{
	int	i;

	mlx_put_image_to_window(data->mlx, data->win, data->image.player_down,
		data->entity.player_x * 64, data->entity.player_y * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->image.exit,
		data->entity.exit_x * 64, data->entity.exit_y * 64);
	if (collectible_load(data))
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

static void	init_data(t_data *data)
{
	data->map.size_x = 0;
	data->map.size_y = 0;
	data->map.p_count = 0;
	data->map.c_count = 0;
	data->map.x_count = 0;
	data->map.collected_c_count = 0;
	data->entity.exit_x = 0;
	data->entity.exit_y = 0;
	data->entity.player_x = 0;
	data->entity.player_y = 0;
	data->entity.player_moves = 0;
	data->image.img_height = 64;
	data->image.img_width = 64;
}

int	init(t_data *data, char *path)
{
	init_data(data);
	if (init_map(data, path))
		return (1);
	if (init_window(data))
		return (1);
	apply_wall_and_floor_textures(data);
	if (init_entities(data))
		return (1);
	return (0);
}
