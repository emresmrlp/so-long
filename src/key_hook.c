/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:23:45 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/09 11:49:19 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/error.h"

int	click_hook(t_data *data)
{
	ft_printf("--------------------------------------------------\n");
	ft_printf("\n");
	ft_printf("(-_-) You exited the game.\n");
	ft_printf("You moved %d times before leave...\n", data->entity.player_moves);
	ft_printf("\n");
	ft_printf("--------------------------------------------------\n");
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (1);
}

int	key_hook(int key, t_data *data)
{
	if (key == 65307)
	{
		ft_printf("--------------------------------------------------\n");
		ft_printf("\n");
		ft_printf("(-_-) You exited the game.\n");
		ft_printf("You moved %d times before leave...\n",
			data->entity.player_moves);
		ft_printf("\n");
		ft_printf("--------------------------------------------------\n");
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
		return (1);
	}
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

void	parse_keys(t_data *data)
{
	mlx_hook(data->win, 17, 0, click_hook, data);
	mlx_key_hook(data->win, key_hook, data);
}
