/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:53:42 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/27 19:13:30 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	game_cleanup(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	free_all(data);
}

int	game_destroy(t_data *data)
{
	game_cleanup(data);
	exit(1);
	return (1);
}

int	game_won(t_data *data)
{
	ft_printf("--------------------------------------------------\n");
	ft_printf("\n");
	ft_printf("(^_^) Yeey! Congratulations! You won the game!\n");
	ft_printf("You moved %d times. Can you do better next time?\n",
		data->entity.player_moves + 1);
	ft_printf("\n");
	ft_printf("--------------------------------------------------\n");
	game_cleanup(data);
	exit(0);
	return (1);
}

int	game_exit(t_data *data)
{
	ft_printf("--------------------------------------------------\n");
	ft_printf("\n");
	ft_printf("(-_-) You exited the game.\n");
	ft_printf("You moved %d times before leave...\n", data->entity.player_moves);
	ft_printf("\n");
	ft_printf("--------------------------------------------------\n");
	game_cleanup(data);
	exit(0);
	return (1);
}
