/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:23:45 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/07 20:08:32 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/error.h"

int	click_hook(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (1);
}

int	key_hook(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
		return (1);
	}
	if (key == 13 || key == 126)
		move_up(data);
	if (key == 0 || key == 123)
		move_left(data);
	if (key == 1 || key == 125)
		move_down(data);
	if (key == 2 || key == 124)
		move_right(data);
	/* - LINUX -
	if (key == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
		return (1);
	}
	if (key == 119 || key == 65362)
		printf("W\n");
	if (key == 97 || key == 65361)
		printf("A\n");
	if (key == 115 || key == 65364)
		printf("S\n");
	if (key == 100 || key == 65363)
		printf("D\n");*/
	return (0);
}

void	parse_keys(t_data *data)
{
	mlx_hook(data->win, 17, 0, click_hook, data);
	mlx_key_hook(data->win, key_hook, data);
}
