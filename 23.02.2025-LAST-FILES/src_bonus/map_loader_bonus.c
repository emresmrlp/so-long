/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:20:51 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/22 16:37:16 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"
#include <fcntl.h>

static int	allocate_map_row(int i, char *line, t_data *data)
{
	int	j;

	j = 0;
	data->map.map[i] = (char *)ft_calloc(data->map.size_x + 1, 1);
	if (!data->map.map[i])
	{
		free(line);
		return (1);
	}
	while (j < data->map.size_x && line[j] != '\0' && line[j] != '\n')
	{
		data->map.map[i][j] = line[j];
		j++;
	}
	data->map.map[i][j] = '\0';
	return (0);
}

static int	read_map_rows(t_data *data, const char *map_path)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (error_handler(ERROR_INVALID_MAP));
	line = get_next_line(fd);
	while (line != NULL && i < data->map.size_y)
	{
		if (allocate_map_row(i, line, data))
		{
			free(line);
			close(fd);
			return (error_handler(ERROR_MAP_ALLOCATION));
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	data->map.map[i] = NULL;
	close(fd);
	return (0);
}

int	load_map(t_data *data, const char *map_path)
{
	data->map.size_x = get_map_size(map_path, get_map_width);
	data->map.size_y = get_map_size(map_path, get_map_height);
	if (data->map.size_x < 0 || data->map.size_y < 0)
		return (error_handler(ERROR_INVALID_MAP));
	data->map.map = (char **)ft_calloc(data->map.size_y + 1, sizeof(char *));
	if (!data->map.map)
		return (error_handler(ERROR_MAP_INIT));
	if (read_map_rows(data, map_path))
		return (1);
	return (0);
}
