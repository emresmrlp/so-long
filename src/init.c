/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:43:23 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/31 19:12:30 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"
#include "../include/error.h"
#include "../include/libft.h"
#include "../include/game.h"
#include "../include/init.h"
#include "../include/free.h"
#include <fcntl.h>

static int	init_window(t_game *game, t_map *map);

static int	init_map(t_game *game, t_map *map, char *map_path);

int	init_game(t_game *game, t_map *map, char *map_path)
{
	if (init_map(game, map, map_path))
		return (1);
	if (init_window(game, map))
		return (1);
	return (0);
}

static int	init_window(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (error_handler(ERROR_MINILIBX_INIT, game, map));
	game->win = mlx_new_window(game->mlx, map->size_x * 32,
			map->size_y * 32, "so_long");
	if (!game->win)
		return (error_handler(ERROR_WINDOW_INIT, game, map));
	mlx_loop(game->mlx);
	return (0);
}

static int	init_map(t_game *game, t_map *map, char *map_path)
{
	if (has_valid_path(map_path))
		return (error_handler(ERROR_INVALID_FILE, game, map));
	if (parse_map(map, map_path))
	{
		free_game(game);
		return (1);
	}
	if (check_map(map))
	{
		free_game(game);
		return (1);
	}
	return (0);
}
