/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:04:52 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/09 11:48:02 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "../external/mlx/mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_map
{
	char	**map;
	char	**copy;
	int		size_x;
	int		size_y;
	int		p_count;
	int		c_count;
	int		collected_c_count;
	int		x_count;
}	t_map;

typedef struct s_image
{
	int		img_width;
	int		img_height;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*exit_player;
	void	*collectible;
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
}	t_image;

typedef struct s_entity
{
	int	exit_x;
	int	exit_y;
	int	**coll;
	int	player_x;
	int	player_y;
	int	player_moves;
}	t_entity;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	t_map		map;
	t_image		image;
	t_entity	entity;
}	t_data;

void	parse_keys(t_data *data);
int		parse_collectibles(t_data *data);
void	fill_background(t_data *data);
int		check_valid_path(t_data *data);
int		free_all(t_data *data);
void	free_copy_map(t_data *data);
int		count_map_file(const char *map_path, int (*f)(int*, char*));
int		count_width(int *counter, char *line);
int		count_height(int *counter, char *line);
int		init_map(t_data *data, char *map_path);
int		init_window(t_data *data);
int		init_textures(t_data *data);
int		init_entities(t_data *data);
void	check_collectible(t_data *data, int x, int y);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
int		check_map(t_data *data);
int		check_file_valid_path(char *map_path);
int		parse_map_textures(t_data *data);
int		parse_player_textures(t_data *data);
int		parse_extra_textures(t_data *data);
int		parse_map(t_data *data, const char *map_path);

#endif