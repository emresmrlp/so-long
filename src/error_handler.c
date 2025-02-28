/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:59:46 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/27 19:13:42 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	error_handler(char *error)
{
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(error, 2);
	}
	return (1);
}
