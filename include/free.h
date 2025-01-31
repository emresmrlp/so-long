/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:46:58 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/31 19:02:41 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H
# include "game.h"
# include "map.h"
# include <stdlib.h>

void	free_all(t_game *game, t_map *map);
void	free_game(t_game *game);
void	free_map(t_map *map);

#endif