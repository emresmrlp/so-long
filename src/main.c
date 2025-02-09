/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:21:30 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/09 11:47:38 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/error.h"

static void	init(t_data *data)
{
	data->map.size_x = 0;
	data->map.size_y = 0;
	data->map.p_count = 0;
	data->map.c_count = 0;
	data->map.collected_c_count = 0;
	data->map.x_count = 0;
	data->entity.exit_x = 0;
	data->entity.exit_y = 0;
	data->entity.coll = NULL;
	data->entity.player_x = 0;
	data->entity.player_y = 0;
	data->entity.player_moves = 0;
	data->map.map = NULL;
	data->map.copy = NULL;
	data->image.img_height = 64;
	data->image.img_width = 64;
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (error_handler(ERROR_INVALID_ARG));
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (error_handler(ERROR_GAME_ALLOCATION));
	init(data);
	if (init_map(data, av[1]))
		return (free_all(data));
	if (init_window(data))
		return (free_all(data));
	if (check_valid_path(data))
		return (free_all(data));
	if (init_textures(data))
		return (free_all(data));
	fill_background(data);
	if (init_entities(data))
		return (free_all(data));
	mlx_loop(data->mlx);
	free_all(data);
	return (0);
}
