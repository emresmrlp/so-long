/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:21:30 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/22 16:37:26 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (error_handler(ERROR_INVALID_ARG));
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (error_handler(ERROR_GAME_ALLOCATION));
	if (init(data, av[1]))
		return (1);
	mlx_loop(data->mlx);
	free_all(data);
	return (0);
}
