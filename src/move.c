/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:19:10 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/07 20:02:13 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/error.h"

static int	check_conditions(t_data *data)
{
	if (data->map.collected_c_count == data->map.c_count)
	{
		ft_printf("--------------------------------------------------\n");
		ft_printf("\n");
		ft_printf("(^_^) Yeey! Congratulations! You won the game!\n");
		ft_printf("\n");
		ft_printf("--------------------------------------------------\n");
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
		return (1);
	}
	else
		ft_printf("(o_o) Collect all collectibles to finish!\n");
	return (0);
}

void	move_up(t_data *data)
{
	if (data->map.map[data->entity.player_y - 1][data->entity.player_x] != '1')
	{
		if (data->entity.player_x == data->entity.exit_x
			&& data->entity.player_y - 1 == data->entity.exit_y)
			check_conditions(data);
		check_collectible(data, data->entity.player_x,
			data->entity.player_y - 1);
		mlx_put_image_to_window(data->mlx, data->win, data->image.floor,
			data->entity.player_x * 64, data->entity.player_y * 64);
		if (data->entity.player_x == data->entity.exit_x
			&& data->entity.player_y == data->entity.exit_y)
			mlx_put_image_to_window(data->mlx, data->win, data->image.exit,
				data->entity.player_x * 64, data->entity.player_y * 64);
		data->entity.player_y--;
		mlx_put_image_to_window(data->mlx, data->win, data->image.player_up,
			data->entity.player_x * 64, data->entity.player_y * 64);
		data->entity.player_moves++;
		ft_printf("Number of movements: %d\n", data->entity.player_moves);
	}
}

void	move_down(t_data *data)
{
	if (data->map.map[data->entity.player_y + 1][data->entity.player_x] != '1')
	{
		if (data->entity.player_x == data->entity.exit_x
			&& data->entity.player_y + 1 == data->entity.exit_y)
			check_conditions(data);
		check_collectible(data, data->entity.player_x,
			data->entity.player_y + 1);
		mlx_put_image_to_window(data->mlx, data->win, data->image.floor,
			data->entity.player_x * 64, data->entity.player_y * 64);
		if (data->entity.player_x == data->entity.exit_x
			&& data->entity.player_y == data->entity.exit_y)
			mlx_put_image_to_window(data->mlx, data->win, data->image.exit,
				data->entity.player_x * 64, data->entity.player_y * 64);
		data->entity.player_y++;
		mlx_put_image_to_window(data->mlx, data->win, data->image.player_down,
			data->entity.player_x * 64, data->entity.player_y * 64);
		data->entity.player_moves++;
		ft_printf("Number of movements: %d\n", data->entity.player_moves);
	}
}

void	move_right(t_data *data)
{
	if (data->map.map[data->entity.player_y][data->entity.player_x + 1] != '1')
	{
		if (data->entity.player_x + 1 == data->entity.exit_x
			&& data->entity.player_y == data->entity.exit_y)
			check_conditions(data);
		check_collectible(data, data->entity.player_x + 1,
			data->entity.player_y);
		mlx_put_image_to_window(data->mlx, data->win, data->image.floor,
			data->entity.player_x * 64, data->entity.player_y * 64);
		if (data->entity.player_x == data->entity.exit_x
			&& data->entity.player_y == data->entity.exit_y)
			mlx_put_image_to_window(data->mlx, data->win, data->image.exit,
				data->entity.player_x * 64, data->entity.player_y * 64);
		data->entity.player_x++;
		mlx_put_image_to_window(data->mlx, data->win, data->image.player_right,
			data->entity.player_x * 64, data->entity.player_y * 64);
		data->entity.player_moves++;
		ft_printf("Number of movements: %d\n", data->entity.player_moves);
	}
}

void	move_left(t_data *data)
{
	if (data->map.map[data->entity.player_y][data->entity.player_x - 1] != '1')
	{
		if (data->entity.player_x - 1 == data->entity.exit_x
			&& data->entity.player_y == data->entity.exit_y)
			check_conditions(data);
		check_collectible(data, data->entity.player_x - 1,
			data->entity.player_y);
		mlx_put_image_to_window(data->mlx, data->win, data->image.floor,
			data->entity.player_x * 64, data->entity.player_y * 64);
		if (data->entity.player_x == data->entity.exit_x
			&& data->entity.player_y == data->entity.exit_y)
			mlx_put_image_to_window(data->mlx, data->win, data->image.exit,
				data->entity.player_x * 64, data->entity.player_y * 64);
		data->entity.player_x--;
		mlx_put_image_to_window(data->mlx, data->win, data->image.player_left,
			data->entity.player_x * 64, data->entity.player_y * 64);
		data->entity.player_moves++;
		ft_printf("Number of movements: %d\n", data->entity.player_moves);
	}
}
