/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:25:45 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/22 20:05:24 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int count, int size)
{
	unsigned char	*buffer;
	int				i;

	buffer = malloc(count * size);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		buffer[i] = 0;
		i++;
	}
	return ((void *)buffer);
}
