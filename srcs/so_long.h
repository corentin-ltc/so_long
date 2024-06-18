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

typedef struct s_valid_map
{
	int	height;
	int	lenght;
	char	*line;
	bool	has_a_floor;
	bool	has_an_exit;
	int	nbr_of_items;
	bool	has_a_start;
}		t_valid_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;
}		t_data;

char	*get_next_line(int fd);
void	map_is_valid(char *file);
void	display_error(char *line);
char	**map_is_possible(char *file, int lenght, int height, int nbr_of_items);





#endif