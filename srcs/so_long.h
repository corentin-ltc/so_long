#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h> 
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int	bits_per_pixels;
	int	endian;
	int	line_len;
}		t_img;

typedef struct s_pathfinder
{
	int	fd;
	int	sz;
	char	**map;
	char	**visited;
	char	*brut_map;
}		t_pathfinder;

typedef struct s_valid_map
{
	int	height;
	int	width;
	char	*line;
	bool	has_a_floor;
	bool	has_an_exit;
	int	nbr_of_items;
	bool	has_a_start;
	int	spawn_y;
	int	spawn_x;
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
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	t_img	img;
	t_valid_map *map_info;
	t_game	*game;
}		t_data;

char	*get_next_line(int fd);
char	**map_is_valid(char *file, t_valid_map *map);
void	display_error(char *line);
char	**map_is_possible(char *file, t_valid_map *map_info);
void	freemap(char **split, char **split2, int display_error);



#endif