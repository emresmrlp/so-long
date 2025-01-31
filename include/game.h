/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:46:55 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/31 18:50:44 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../external/mlx/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
}	t_game;

#endif