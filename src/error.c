/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:06:35 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/31 19:12:48 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"
#include "../include/game.h"
#include "../include/map.h"
#include "../include/libft.h"
#include "../include/free.h"

//   LINUX için game->mlx mlx_destroy_display kullanılmalı mı?!

int	error_handler(char *error, t_game *game, t_map *map)
{
	if (error)
		ft_putstr_fd(error, 1);
	if (game)
		free_game(game);
	if (map)
		free_map(map);
	return (1);
}
