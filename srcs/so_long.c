/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:20:20 by cle-tort          #+#    #+#             */
/*   Updated: 2024/06/20 09:47:19 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include "so_long.h"


void	init_images(t_data *data, t_game *game, char **map)
{
	int	x;
	int	y;

	if(!(game->im_wall = mlx_xpm_file_to_image(data->mlx_ptr, "wall.xpm", &x, &y)))
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);		
		freemap(data->map, 0, 3);
	}
	if(!(game->im_wall_shadow = mlx_xpm_file_to_image(data->mlx_ptr, "wall_shadow.xpm", &x, &y)))
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		freemap(map, 0, 1);
	}
	if(!(game->im_floor = mlx_xpm_file_to_image(data->mlx_ptr, "floor.xpm", &x, &y)))
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_image(data->mlx_ptr, game->im_wall_shadow);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		freemap(map, 0, 1);
	}
	if(!(game->im_exit = mlx_xpm_file_to_image(data->mlx_ptr, "closed_chest.xpm", &x, &y)))
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_image(data->mlx_ptr, game->im_floor);
		mlx_destroy_image(data->mlx_ptr, game->im_wall_shadow);
		mlx_destroy_image(data->mlx_ptr, game->im_floor);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		freemap(map, 0, 1);
	}
	if(!(game->im_player = mlx_xpm_file_to_image(data->mlx_ptr, "walterwhite.xpm", &x, &y)))
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_image(data->mlx_ptr, game->im_floor);
		mlx_destroy_image(data->mlx_ptr, game->im_wall_shadow);
		mlx_destroy_image(data->mlx_ptr, game->im_floor);
		mlx_destroy_image(data->mlx_ptr, game->im_exit);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		freemap(map, 0, 1);
	}
	if(!(game->im_coin_f1 = mlx_xpm_file_to_image(data->mlx_ptr, "coin_f1.xpm", &x, &y)))
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_image(data->mlx_ptr, game->im_floor);
		mlx_destroy_image(data->mlx_ptr, game->im_wall_shadow);
		mlx_destroy_image(data->mlx_ptr, game->im_floor);
		mlx_destroy_image(data->mlx_ptr, game->im_exit);
		mlx_destroy_image(data->mlx_ptr, game->im_player);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		freemap(map, 0, 1);
	}
	if(!(game->im_coin_f2 = mlx_xpm_file_to_image(data->mlx_ptr, "coin_f2.xpm", &x, &y)))
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_image(data->mlx_ptr, game->im_floor);
		mlx_destroy_image(data->mlx_ptr, game->im_wall_shadow);
		mlx_destroy_image(data->mlx_ptr, game->im_floor);
		mlx_destroy_image(data->mlx_ptr, game->im_exit);
		mlx_destroy_image(data->mlx_ptr, game->im_player);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f1);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		freemap(map, 0, 1);
	}
	if(!(game->im_coin_f3 = mlx_xpm_file_to_image(data->mlx_ptr, "coin_f3.xpm", &x, &y)))
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_image(data->mlx_ptr, game->im_floor);
		mlx_destroy_image(data->mlx_ptr, game->im_wall_shadow);
		mlx_destroy_image(data->mlx_ptr, game->im_floor);
		mlx_destroy_image(data->mlx_ptr, game->im_exit);
		mlx_destroy_image(data->mlx_ptr, game->im_player);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f1);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f2);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		freemap(map, 0, 1);
	}
	if(!(game->im_coin_f4 = mlx_xpm_file_to_image(data->mlx_ptr, "coin_f4.xpm", &x, &y)))
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_image(data->mlx_ptr, game->im_floor);
		mlx_destroy_image(data->mlx_ptr, game->im_wall_shadow);
		mlx_destroy_image(data->mlx_ptr, game->im_floor);
		mlx_destroy_image(data->mlx_ptr, game->im_exit);
		mlx_destroy_image(data->mlx_ptr, game->im_player);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f1);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f2);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f3);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		freemap(map, 0, 1);
	}
	if(!(game->im_coin_f5 = mlx_xpm_file_to_image(data->mlx_ptr, "coin_f5.xpm", &x, &y)))
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_image(data->mlx_ptr, game->im_floor);
		mlx_destroy_image(data->mlx_ptr, game->im_wall_shadow);
		mlx_destroy_image(data->mlx_ptr, game->im_floor);
		mlx_destroy_image(data->mlx_ptr, game->im_exit);
		mlx_destroy_image(data->mlx_ptr, game->im_player);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f1);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f2);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f3);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f4);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		freemap(map, 0, 1);
	}
}

int	set_elements(t_data *data)
{
	int	y;
	int	x;
	static  unsigned int i = 0;
	char	*number_of_movements;

	y = 0;
	while (y < data->map_info->height)
	{
		x = 0;
		while (x < data->map_info->width)
		{
			if (data->map[y][x] == 'P' && data->exit_x == x && data->exit_y == y && data->map_info->items_collected == data->map_info->nbr_of_items)
			{
				ft_putstr_fd("YOU WON!", 1);
				mlx_destroy_window(data->mlx_ptr, data->mlx_win);
				free_images(data);
				mlx_destroy_display(data->mlx_ptr);
				free(data->mlx_ptr);		
				freemap(data->map, 0, 3);
			}
			if(data->map[y][x] == '1' && y != data->map_info->height - 1 && data->map[y + 1][x] == '1' )
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->game->im_wall, x * 64, y * 64);
			else if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->game->im_wall_shadow, x * 64, y * 64);
			if(data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->game->im_floor, x * 64, y * 64);
			if(data->map[y][x] == 'E' || (data->exit_x == x && data->exit_y == y && data->map[y][x] != 'P'))
			{
				data->exit_x = x;
				data->exit_y = y;
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->game->im_exit, x * 64, y * 64);
			}
			if(data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->game->im_player, x * 64, y * 64);
			if(data->map[y][x] == 'C')
			{
				if (i <= 1000 / 7)
					mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->game->im_coin_f1, x * 64, y * 64);
				if (i > 1000 / 7 && i <= 2000 / 7)
					mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->game->im_coin_f2, x * 64, y * 64);
				if (i > 2000 / 7 && i <= 3000 / 7)
					mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->game->im_coin_f3, x * 64, y * 64);
				if (i > 3000 / 7 && i <= 4000 / 7)
					mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->game->im_coin_f4, x * 64, y * 64);
				if (i > 4000 / 7 && i <= 5000 / 7)
					mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->game->im_coin_f5, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
	i++;
	if (i > 5000 / 7)
		i = 0;
	mlx_string_put(data->mlx_ptr, data->mlx_win, 30, 20, 0xFFFFFFF, " Movements counter: ");
	number_of_movements = ft_itoa(data->movements_count);
	if (!number_of_movements)
	{
		write(1, "Error\n Allocation failed.\n", 27);
		exit_game(data);
	}
	mlx_string_put(data->mlx_ptr, data->mlx_win, 150, 20, 0xFFFFFFF, number_of_movements);
	free(number_of_movements);
}

void	move_up(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P' && y > 1 && data->map[y - 1][x] != '1')
			{
				++data->movements_count;
				if (data->map[y - 1][x] == 'C')
					data->map_info->items_collected++;
				data->map[y][x] = '0';
				data->map[y - 1][x] = 'P';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_down(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P' && y < data->map_info->height - 2 && data->map[y + 1][x] != '1')
			{
				++data->movements_count;
				if (data->map[y + 1][x] == 'C')
					data->map_info->items_collected++;
				data->map[y][x] = '0';
				data->map[y + 1][x] = 'P';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_left(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P' && x > 1 && data->map[y][x - 1] != '1')
			{
				++data->movements_count;
				if (data->map[y][x - 1] == 'C')
					data->map_info->items_collected++;
				data->map[y][x] = '0';
				data->map[y][x - 1] = 'P';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_right(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P' && x < data->map_info->width - 2 && data->map[y][x + 1] != '1')
			{
				++data->movements_count;
				if (data->map[y][x + 1] == 'C')
					data->map_info->items_collected++;
				data->map[y][x] = '0';
				data->map[y][x + 1] = 'P';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	free_images(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->game->im_coin_f1);
	mlx_destroy_image(data->mlx_ptr, data->game->im_coin_f2);
	mlx_destroy_image(data->mlx_ptr, data->game->im_coin_f3);
	mlx_destroy_image(data->mlx_ptr, data->game->im_coin_f4);
	mlx_destroy_image(data->mlx_ptr, data->game->im_coin_f5);
	mlx_destroy_image(data->mlx_ptr, data->game->im_wall);
	mlx_destroy_image(data->mlx_ptr, data->game->im_wall_shadow);
	mlx_destroy_image(data->mlx_ptr, data->game->im_player);
	mlx_destroy_image(data->mlx_ptr, data->game->im_exit);
	mlx_destroy_image(data->mlx_ptr, data->game->im_floor);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		exit_game(data);
	if (keysym == XK_w)
	 	move_up(data);
	else if (keysym == XK_s)
	 	move_down(data);
	else if (keysym == XK_a)
	 	move_left(data);
	else if (keysym == XK_d)
	 	move_right(data);
	return (0);
}

int exit_game(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free_images(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	freemap(data->map, 0, 3);
}

int main(int argc, char **argv)
{
	t_valid_map	map_info;
	t_data		data;
	t_game		game;

	if (argc != 2)
	{
		write(1, "Error\nWrong number of arguments.\n", 34);
		exit(1);
	}
	data.map = map_is_valid(argv[1], &map_info);
	data.exit_x = -1;
	data.movements_count = 0;
	if ((data.mlx_ptr = mlx_init()) == NULL)
		freemap(data.map, 0, 1);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, map_info.width * 64, map_info.height * 64, "so_long")) == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		freemap(data.map, 0, 1);
	}
	data.game = &game;
	init_images(&data, &game, data.map);
	data.map_info = &map_info;
	mlx_hook(data.mlx_win, 2, 1L<<0, handle_input, &data);
	mlx_loop_hook(data.mlx_ptr, set_elements, &data);
	mlx_hook(data.mlx_win, DestroyNotify, 0, exit_game, &data);
	mlx_loop(data.mlx_ptr);
}