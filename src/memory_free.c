/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:55:29 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/27 19:14:08 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_map(t_data *data)
{
	int	i;

	i = data->map.size_y;
	if (data->map.map)
	{
		while (i--)
		{
			if (data->map.map[i])
			{
				free(data->map.map[i]);
				data->map.map[i] = NULL;
			}
		}
		free(data->map.map);
		data->map.map = NULL;
	}
}

static void	free_collectibles(t_data *data)
{
	int	i;

	i = 0;
	if (data->entity.coll)
	{
		while (i < data->map.c_count)
		{
			if (data->entity.coll[i])
			{
				free(data->entity.coll[i]);
				data->entity.coll[i] = NULL;
			}
			i++;
		}
		free(data->entity.coll);
		data->entity.coll = NULL;
	}
}

static int	free_textures(t_data *data)
{
	if (data->mlx)
	{
		if (data->image.wall)
			mlx_destroy_image(data->mlx, data->image.wall);
		if (data->image.floor)
			mlx_destroy_image(data->mlx, data->image.floor);
		if (data->image.exit)
			mlx_destroy_image(data->mlx, data->image.exit);
		if (data->image.exit_open)
			mlx_destroy_image(data->mlx, data->image.exit_open);
		if (data->image.exit_player)
			mlx_destroy_image(data->mlx, data->image.exit_player);
		if (data->image.collectible)
			mlx_destroy_image(data->mlx, data->image.collectible);
		if (data->image.player_down)
			mlx_destroy_image(data->mlx, data->image.player_down);
		if (data->image.player_left)
			mlx_destroy_image(data->mlx, data->image.player_left);
		if (data->image.player_right)
			mlx_destroy_image(data->mlx, data->image.player_right);
		if (data->image.player_up)
			mlx_destroy_image(data->mlx, data->image.player_up);
	}
	return (1);
}

int	free_all(t_data *data)
{
	if (data)
	{
		free_map(data);
		free_collectibles(data);
		free_textures(data);
		if (data->mlx)
		{
			mlx_destroy_display(data->mlx);
			free(data->mlx);
			data->mlx = NULL;
		}
		free(data);
		data = NULL;
	}
	return (1);
}
