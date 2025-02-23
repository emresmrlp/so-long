/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:01:42 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/22 20:06:41 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (*(str + i) != (char)c && *(str + i) != '\0')
		i++;
	if (*(str + i) == (char)c)
		return ((char *)(str + i));
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buffer;
	int		i;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!buffer)
		return (NULL);
	i = -1;
	while (s1[++i])
		buffer[i] = s1[i];
	while (s2[i - ft_strlen(s1)])
	{
		buffer[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	buffer[i] = '\0';
	return (free(s1), buffer);
}
