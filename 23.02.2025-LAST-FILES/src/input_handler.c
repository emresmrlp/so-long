/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:23:45 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/22 15:34:25 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	handle_exit_click(t_data *data)
{
	return (game_exit(data));
}

static int	handle_keypress(int key, t_data *data)
{
	if (key == 65307)
		return (game_exit(data));
	if (key == 119 || key == 65362)
		move_up(data);
	if (key == 97 || key == 65361)
		move_left(data);
	if (key == 115 || key == 65364)
		move_down(data);
	if (key == 100 || key == 65363)
		move_right(data);
	return (0);
}

void	register_input_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 0, handle_exit_click, data);
	mlx_hook(data->win, 2, (1L << 0), handle_keypress, data);
}
