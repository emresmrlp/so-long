/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 08:35:51 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/31 17:30:02 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game.h"
#include "../include/libft.h"
#include "../include/error.h"
#include "../include/map.h"
#include "../include/init.h"

int	main(int ac, char **av)
{
	t_game	*game;
	t_map	*map;

	if (ac != 2)
		return (error_handler(ERROR_INVALID_ARG, NULL, NULL));
	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		return (error_handler(ERROR_GAME_ALLOCATION, game, NULL));
	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (error_handler(ERROR_MAP_ALLOCATION, game, map));
	if (init_game(game, map, av[1]))
		return (1);
	return (0);
}
