/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:03:41 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/27 16:26:49 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_INVALID_ARG "(-) Usage: ./so_long maps/map_name.ber\n"
# define ERROR_INVALID_MAP "(-) Invalid map!\n"
# define ERROR_INVALID_FILE "(-) Invalid file extension! (only .ber)\n"
# define ERROR_CHECKED_ALLOCATION "(-) Checked allocation failed!\n"
# define ERROR_GAME_ALLOCATION "(-) Game allocation failed!\n"
# define ERROR_PARAM_ALLOCATION "(-) Param allocation failed!\n"
# define ERROR_COLLECT_ALLOCATION "(-) Collectible allocation failed!\n"
# define ERROR_IMG_ALLOCATION "(-) Image allocation failed!\n"
# define ERROR_MINILIBX_INIT "(-) MiniLibX initalization failed!\n"
# define ERROR_WINDOW_INIT "(-) Window initialization failed!\n"
# define ERROR_MAP_INIT "(-) Map initialization failed!\n"
# define ERROR_TEXTURE_INIT "(-) Texture initialization failed!\n"
# define ERROR_MAP_ALLOCATION "(-) Map allocation failed!\n"
# define ERROR_MAP_WALLS "(-) Map must be surrounded by walls!\n"
# define ERROR_MAP_ENTITY "(-) 1 player, 1 exit, and 1+ collectible.\n"
# define ERROR_MAP_MUST_RECTANGULAR "(-) Map must be rectangular!\n"
# define ERROR_MAP_INV_CONTAINS "(-) Map contains invalid characters!\n"
# define ERROR_MAP_NO_VALID_PATH "(-) No valid path found!\n"

int	error_handler(char *error);

#endif