/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:32 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/22 16:45:46 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int uns, int caps)
{
	char	*base;
	int		counter;

	counter = 0;
	if (caps == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	counter += ft_print_base(uns, base);
	return (counter);
}
