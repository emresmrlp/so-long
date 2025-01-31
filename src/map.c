/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:39:24 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/31 19:01:58 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"
#include "../include/libft.h"
#include "../include/error.h"

static int	validate_entities(t_map *map);

static int	is_map_closed(t_map *map);

int	check_map(t_map *map)
{
	if (map->size_x == map->size_y)
		return (error_handler(ERROR_MAP_MUST_RECTANGULAR, NULL, map));
	if (map->size_x < 3 || map->size_y < 3)
		return (error_handler(ERROR_MAP_NO_VALID_PATH, NULL, map));
	if (is_map_closed(map))
		return (error_handler(ERROR_MAP_WALLS, NULL, map));
	if (validate_entities(map))
		return (1);
	return (0);
}

int	has_valid_path(char *map_path)
{
	char	*extension;

	extension = ft_strrchr(map_path, '.');
	if (!extension || ft_strncmp(extension, ".ber", 5) != 0)
		return (1);
	return (0);
}

static int	validate_entities(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
				map->p_count++;
			else if (map->map[i][j] == 'C')
				map->c_count++;
			else if (map->map[i][j] == 'X')
				map->x_count++;
			else if (map->map[i][j] != '1' && map->map[i][j] != '0')
				return (error_handler(ERROR_MAP_CONTAINS, NULL, map));
			j++;
		}
		i++;
	}
	if (map->p_count != 1 || map->x_count != 1 || map->c_count < 1)
		return (error_handler(ERROR_MAP_ENTITY, NULL, map));
	return (0);
}

static int	is_map_closed(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size_y)
	{
		if (i == 0 || i == map->size_y - 1)
		{
			j = 0;
			while (j < map->size_x)
			{
				if (map->map[i][j++] != '1')
					return (1);
			}
		}
		else
		{
			if (map->map[i][0] != '1' || map->map[i][map->size_x - 1] != '1')
				return (1);
		}
		i++;
	}
	return (0);
}
