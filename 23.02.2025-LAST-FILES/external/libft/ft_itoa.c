/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:09:45 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/22 20:05:19 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getlen(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*buffer;

	len = ft_getlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	buffer = malloc(len + 1);
	if (buffer == NULL)
		return (NULL);
	buffer[len] = '\0';
	if (n < 0)
	{
		buffer[0] = '-';
		n = -n;
	}
	if (n == 0)
		buffer[len - 1] = '0';
	while (len > 0)
	{
		if (n == 0 && len == 1)
			break ;
		buffer[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (buffer);
}