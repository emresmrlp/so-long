/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:46:42 by ysumeral          #+#    #+#             */
/*   Updated: 2025/01/31 18:50:32 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	char	**map;
	int		p_count;
	int		c_count;
	int		x_count;
	int		size_x;
	int		size_y;
}	t_map;

int	check_map(t_map *map);
int	has_valid_path(char *map_path);
int	parse_map(t_map *map, const char *map_path);
int	count_width(int *counter, char *line);
int	count_height(int *counter, char *line);
int	count_map_file(const char *map_path, int (*f)(int*, char*));

#endif