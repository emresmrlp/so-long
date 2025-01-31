/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:41:55 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/31 18:42:18 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/map.h"
#include "../include/free.h"

void	free_game(t_game *game)
{
	if (game)
	{
		if (game->mlx)
			free(game->mlx);
		free(game);
	}
}

void	free_map(t_map *map)
{
	if (map)
	{
		if (map->map)
		{
			while (map->size_y--)
			{
				free(map->map[map->size_y]);
				map->map[map->size_y] = NULL;
			}
			free(map->map);
			map->map = NULL;
		}
		free(map);
		map = NULL;
	}
}

void	free_all(t_game *game, t_map *map)
{
	free_game(game);
	free_map(map);
}
