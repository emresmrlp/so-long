/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:19:10 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/22 16:36:42 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

static int	move_handler(t_data *data, int x, int y)
{
	collecitble_check(data, x, y);
	if (x == data->entity.exit_x && y == data->entity.exit_y)
	{
		if (data->map.collected_c_count == data->map.c_count)
			game_won(data);
		else
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->image.exit_player, (x * 64), (y * 64));
			ft_printf("(o_o) Collect all collectibles to finish!\n");
		}
	}
	return (0);
}

void	move_up(t_data *data)
{
	int	x;
	int	y;

	x = data->entity.player_x;
	y = data->entity.player_y;
	if (data->map.map[y - 1][x] != '1')
	{
		if (x == data->entity.exit_x && y == data->entity.exit_y)
			mlx_put_image_to_window(data->mlx, data->win,
				data->image.exit, x * 64, y * 64);
		else
			mlx_put_image_to_window(data->mlx, data->win,
				data->image.floor, x * 64, y * 64);
		mlx_put_image_to_window(data->mlx, data->win,
			data->image.player_up, x * 64, (y - 1) * 64);
		move_handler(data, x, (y - 1));
		data->entity.player_y--;
		data->entity.player_moves++;
		ft_printf("You moved %d times.\n", data->entity.player_moves);
	}
}

void	move_down(t_data *data)
{
	int	x;
	int	y;

	x = data->entity.player_x;
	y = data->entity.player_y;
	if (data->map.map[y + 1][x] != '1')
	{
		if (x == data->entity.exit_x && y == data->entity.exit_y)
			mlx_put_image_to_window(data->mlx, data->win,
				data->image.exit, x * 64, y * 64);
		else
			mlx_put_image_to_window(data->mlx, data->win,
				data->image.floor, x * 64, y * 64);
		mlx_put_image_to_window(data->mlx, data->win,
			data->image.player_down, x * 64, (y + 1) * 64);
		move_handler(data, x, (y + 1));
		data->entity.player_y++;
		data->entity.player_moves++;
		ft_printf("You moved %d times.\n", data->entity.player_moves);
	}
}

void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->entity.player_x;
	y = data->entity.player_y;
	if (data->map.map[y][x + 1] != '1')
	{
		if (x == data->entity.exit_x && y == data->entity.exit_y)
			mlx_put_image_to_window(data->mlx, data->win,
				data->image.exit, x * 64, y * 64);
		else
			mlx_put_image_to_window(data->mlx, data->win,
				data->image.floor, x * 64, y * 64);
		mlx_put_image_to_window(data->mlx, data->win,
			data->image.player_right, (x + 1) * 64, y * 64);
		move_handler(data, (x + 1), y);
		data->entity.player_x++;
		data->entity.player_moves++;
		ft_printf("You moved %d times.\n", data->entity.player_moves);
	}
}

void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = data->entity.player_x;
	y = data->entity.player_y;
	if (data->map.map[y][x - 1] != '1')
	{
		if (x == data->entity.exit_x && y == data->entity.exit_y)
			mlx_put_image_to_window(data->mlx, data->win,
				data->image.exit, x * 64, y * 64);
		else
			mlx_put_image_to_window(data->mlx, data->win,
				data->image.floor, x * 64, y * 64);
		mlx_put_image_to_window(data->mlx, data->win,
			data->image.player_left, (x - 1) * 64, y * 64);
		move_handler(data, (x - 1), y);
		data->entity.player_x--;
		data->entity.player_moves++;
		ft_printf("You moved %d times.\n", data->entity.player_moves);
	}
}
