/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysumeral <ysumeral@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 20:04:52 by ysumeral          #+#    #+#             */
/*   Updated: 2025/02/22 20:07:33 by ysumeral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "error.h"
# include "../external/libft/libft.h"
# include "../external/get_next_line/get_next_line.h"
# include "../external/ft_printf/ft_printf.h"
# include "../external/mlx/mlx.h"

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
	void	*xpm;
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

int		game_won(t_data *data);
int		game_exit(t_data *data);
void	register_input_hooks(t_data *data);
int		entity_load(t_data *data);
int		collectible_load(t_data *data);
void	collecitble_check(t_data *data, int x, int y);
int		load_map(t_data *data, const char *map_path);
int		validate_map(t_data *data, char *map_path);
int		can_play_map(t_data *data);
int		get_map_size(const char *map_path, int (*f)(int*, char*));
int		get_map_width(int *counter, char *line);
int		get_map_height(int *counter, char *line);
int		load_textures(t_data *data);
void	apply_wall_and_floor_textures(t_data *data);
int		init(t_data *data, char *path);
void	image_cleanup(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
int		free_all(t_data *data);

#endif