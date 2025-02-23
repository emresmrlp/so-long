/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:01:32 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/22 20:06:40 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_leftover(int fd, char *leftover)
{
	char	*buffer;
	ssize_t	bytes_rd;

	bytes_rd = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr(leftover, '\n') == NULL && bytes_rd != 0)
	{
		bytes_rd = read(fd, buffer, BUFFER_SIZE);
		if (bytes_rd == -1)
		{
			free(leftover);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_rd] = '\0';
		leftover = ft_strjoin(leftover, buffer);
	}
	free(buffer);
	return (leftover);
}

static char	*ft_set_leftover(char *leftover)
{
	char	*buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!leftover || leftover[0] == '\0')
		return (NULL);
	while (leftover[i] != '\0' && leftover[i] != '\n')
		i++;
	if (!leftover[i])
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (ft_strlen(leftover) - i + 1));
	if (!buffer)
		return (NULL);
	i++;
	while (leftover[i])
		buffer[j++] = leftover[i++];
	buffer[j] = '\0';
	return (buffer);
}

static char	*ft_get_line(char *leftover)
{
	char	*line;
	int		len;
	int		i;

	if (!leftover || leftover[0] == '\0')
		return (NULL);
	len = 0;
	i = -1;
	while (leftover[len] != '\0' && leftover[len] != '\n')
		len++;
	if (leftover[len] == '\0')
		line = (char *)malloc(sizeof(char) * (len + 1));
	else
		line = (char *)malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	while (leftover[++i] != '\0' && leftover[i] != '\n')
		line[i] = leftover[i];
	if (leftover[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = ft_read_leftover(fd, leftover);
	if (!leftover)
		return (NULL);
	line = ft_get_line(leftover);
	temp = ft_set_leftover(leftover);
	free(leftover);
	leftover = temp;
	return (line);
}
