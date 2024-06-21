/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 02:00:01 by cle-tort          #+#    #+#             */
/*   Updated: 2024/06/21 02:01:23 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h> 
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "../../libft/libft.h"

typedef struct s_pathfinder
{
	int		fd;
	int		sz;
	char	**map;
	char	**visited;
	char	*brut_map;
}		t_pathfinder;

typedef struct s_valid_map
{
	int		height;
	int		width;
	char	*line;
	bool	has_a_floor;
	int		has_an_exit;
	int		nbr_of_items;
	int		items_collected;
	int		has_a_start;
	int		spawn_y;
	int		spawn_x;
}		t_valid_map;

typedef struct s_game
{
	void	*im_wall;
	void	*im_wall_shadow;
	void	*im_coin_f1;
	void	*im_coin_f2;
	void	*im_coin_f3;
	void	*im_coin_f4;
	void	*im_coin_f5;
	void	*im_floor;
	void	*im_player;
	void	*im_exit;
}		t_game;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		**map;
	int			exit_x;
	int			exit_y;
	int			movements_count;
	t_valid_map	*map_info;
	t_game		*game;
}		t_data;

char	*get_next_line(int fd);
char	**map_is_valid(char *file, t_valid_map *map);
void	display_error(char *line);
char	**map_is_possible(char *file, t_valid_map *map_info);
void	freemap(char **split, char **split2, int display_error);
void	free_images(t_data *data);
int		exit_game(t_data *data);
void	free_and_exit(t_data *data);
void	init_images(t_data *data, t_game *game, char **map);
void	init_images1(t_data *data, t_game *game);
void	init_images2(t_data *data, t_game *game);
void	init_images3(t_data *data, t_game *game);
void	init_images4(t_data *data, t_game *game);
void	init_images5(t_data *data, t_game *game);
void	init_images6(t_data *data, t_game *game);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
int		set_elements(t_data *data);
void	set_elements1(t_data *data, int y, int x);
void	set_collectible(t_data *data, int y, int x, int i);
int		handle_input(int keysym, t_data *data);
int		is_only_walls(char *line, bool is_first_line);
void	initialize_struct(t_valid_map *map);

#endif