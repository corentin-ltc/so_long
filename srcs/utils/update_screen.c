/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:03:45 by cle-tort          #+#    #+#             */
/*   Updated: 2024/06/21 01:57:05 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_string(t_data *data)
{
	char	*number_of_movements;

	mlx_string_put(data->mlx_ptr, data->mlx_win, 30, 20,
		0xFFFFFFF, " Movements counter: ");
	number_of_movements = ft_itoa(data->movements_count);
	if (!number_of_movements)
	{
		write(1, "Error\n Allocation failed.\n", 27);
		exit_game(data);
	}
	mlx_string_put(data->mlx_ptr, data->mlx_win, 150, 20,
		0xFFFFFFF, number_of_movements);
	free(number_of_movements);
}

void	set_elements1(t_data *data, int y, int x)
{
	if (data->map[y][x] == 'P' && data->exit_x == x && data->exit_y == y
		&& data->map_info->items_collected == data->map_info->nbr_of_items)
	{
		ft_putstr_fd("YOU WON!", 1);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		free_images(data);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		freemap(data->map, 0, 3);
	}
	if (data->map[y][x] == '1' && y != data->map_info->height - 1
		&& data->map[y + 1][x] == '1' )
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->game->im_wall, x * 64, y * 64);
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->game->im_wall_shadow, x * 64, y * 64);
}

void	set_elements2(t_data *data, int y, int x)
{
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->game->im_floor, x * 64, y * 64);
	if (data->map[y][x] == 'E' || (data->exit_x == x && data->exit_y == y
		&& data->map[y][x] != 'P'))
	{
		data->exit_x = x;
		data->exit_y = y;
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->game->im_exit, x * 64, y * 64);
	}
	if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
			data->game->im_player, x * 64, y * 64);
}

void	set_collectible(t_data *data, int y, int x, int i)
{
	if (data->map[y][x] == 'C')
	{
		if (i <= 1000 / 7)
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
				data->game->im_coin_f1, x * 64, y * 64);
		if (i > 1000 / 7 && i <= 2000 / 7)
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
				data->game->im_coin_f2, x * 64, y * 64);
		if (i > 2000 / 7 && i <= 3000 / 7)
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
				data->game->im_coin_f3, x * 64, y * 64);
		if (i > 3000 / 7 && i <= 4000 / 7)
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
				data->game->im_coin_f4, x * 64, y * 64);
		if (i > 4000 / 7 && i <= 5000 / 7)
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
				data->game->im_coin_f5, x * 64, y * 64);
	}
}

int	set_elements(t_data *data)
{
	int			y;
	int			x;
	static long	i = 0;
	char		*number_of_movements;

	display_string(data);
	y = 0;
	while (y < data->map_info->height)
	{
		x = 0;
		while (x < data->map_info->width)
		{
			set_elements1(data, y, x);
			set_elements2(data, y, x);
			set_collectible(data, y, x, i);
			x++;
		}
		y++;
	}
	i++;
	if (i > 5000 / 7)
		i = 0;
	display_string(data);
}
