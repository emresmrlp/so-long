/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:47:00 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/31 19:02:25 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "game.h"
# include "map.h"
# define ERROR_INVALID_ARG "Error\n(-) Invalid number of arguments!\n"
# define ERROR_INVALID_MAP "Error\n(-) Invalid map!\n"
# define ERROR_INVALID_FILE "Error\n(-) Invalid file extension!\n"
# define ERROR_INVALID_WINDOW_SIZE "Error\n(-) Invalid window size!\n"
# define ERROR_MINILIBX_INIT "Error\n(-) MiniLibX initalization failed!\n"
# define ERROR_WINDOW_INIT "Error\n(-) Window initialization failed!\n"
# define ERROR_GAME_ALLOCATION "Error\n(-) Data allocation failed!\n"
# define ERROR_MAP_ALLOCATION "Error\n(-) Map allocation failed!\n"
# define ERROR_MAP_WALLS "Error\n(-) Map must be surrounded by walls!\n"
# define ERROR_MAP_ENTITY "Error\n(-) 1 player, 1 exit, and 1+ collectible.\n"
# define ERROR_MAP_MUST_RECTANGULAR "Error\n(-) Map must be rectangular!\n"
# define ERROR_MAP_INIT "Error\n(-) Map initialization failed!\n"
# define ERROR_MAP_CONTAINS "Error\n(-) Map contains invalid characters!\n"
# define ERROR_MAP_NO_VALID_PATH "Error\n(-) No valid path found!\n"

int	error_handler(char *error, t_game *game, t_map *map);

#endif