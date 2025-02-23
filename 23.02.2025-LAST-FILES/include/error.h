/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:03:41 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/22 20:09:48 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_INVALID_ARG "Error\n(-) Usage: ./so_long maps/map_name.ber\n"
# define ERROR_INVALID_MAP "Error\n(-) Invalid map!\n"
# define ERROR_INVALID_FILE "Error\n(-) Invalid file extension! (only .ber)\n"
# define ERROR_CHECKED_ALLOCATION "Error\n(-) Checked allocation failed!\n"
# define ERROR_GAME_ALLOCATION "Error\n(-) Game allocation failed!\n"
# define ERROR_PARAM_ALLOCATION "Error\n(-) Param allocation failed!\n"
# define ERROR_COLLECT_ALLOCATION "Error\n(-) Collectible allocation failed!\n"
# define ERROR_IMG_ALLOCATION "Error\n(-) Image allocation failed!\n"
# define ERROR_MINILIBX_INIT "Error\n(-) MiniLibX initalization failed!\n"
# define ERROR_WINDOW_INIT "Error\n(-) Window initialization failed!\n"
# define ERROR_MAP_INIT "Error\n(-) Map initialization failed!\n"
# define ERROR_TEXTURE_INIT "Error\n(-) Texture initialization failed!\n"
# define ERROR_MAP_ALLOCATION "Error\n(-) Map allocation failed!\n"
# define ERROR_MAP_WALLS "Error\n(-) Map must be surrounded by walls!\n"
# define ERROR_MAP_ENTITY "Error\n(-) 1 player, 1 exit, and 1+ collectible.\n"
# define ERROR_MAP_MUST_RECTANGULAR "Error\n(-) Map must be rectangular!\n"
# define ERROR_MAP_INV_CONTAINS "Error\n(-) Map contains invalid characters!\n"
# define ERROR_MAP_NO_VALID_PATH "Error\n(-) No valid path found!\n"

int	error_handler(char *error);

#endif