/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:54:08 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/31 18:11:04 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"
#include "../include/error.h"
#include "../include/libft.h"
#include "../include/game.h"
#include "../include/get_next_line.h"
#include <fcntl.h>

// MAP PARSER FUNCTION ->		Size_x ve size_y'yi map_size.c aracılığıyla
//								belirler ve map'i okur.
// -> ALLOCATE fonksiyonu ->	Satırı alır, okur bu satıra yer ayırır ve
//								map arrayine ekler.
// -> READ ROWS fonksiyonu ->	Verilen dosyayı satır satır okur ve allocate
//								fonksiyonuna göndererek her satır için yer
//								ayırılmasını ve map arrayine eklenmesini sağlar.

static int	allocate_map_row(int *i, char *line, t_map *map);

static int	read_map_rows(int fd, t_map *map);

int	parse_map(t_map *map, const char *map_path)
{
	int		fd;

	map->size_x = count_map_file(map_path, count_width);
	map->size_y = count_map_file(map_path, count_height);
	if (map->size_x < 0 || map->size_y < 0)
		return (error_handler(ERROR_INVALID_MAP, NULL, map));
	map->map = (char **)ft_calloc(map->size_y, sizeof(char *));
	if (!map->map)
		return (error_handler(ERROR_MAP_INIT, NULL, map));
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (error_handler(ERROR_INVALID_MAP, NULL, map));
	if (read_map_rows(fd, map))
	{
		close(fd);
		return (error_handler(ERROR_MAP_ALLOCATION, NULL, map));
	}
	close(fd);
	return (0);
}

static int	allocate_map_row(int *i, char *line, t_map *map)
{
	int	j;

	j = 0;
	map->map[*i] = (char *)ft_calloc(map->size_x + 1, 1);
	if (!map->map[*i])
	{
		free(line);
		return (1);
	}
	while (j < map->size_x)
	{
		map->map[*i][j] = line[j];
		j++;
	}
	map->map[*i][j] = '\0';
	(*i)++;
	return (0);
}

static int	read_map_rows(int fd, t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (allocate_map_row(&i, line, map))
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	map->map[i] = NULL;
	return (0);
}
