/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:20:20 by cle-tort          #+#    #+#             */
/*   Updated: 2024/06/20 12:19:37 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		free_and_exit(&data);
	data.game = &game;
	init_images(&data, &game, data.map);
	data.map_info = &map_info;
	mlx_hook(data.mlx_win, 2, 1L<<0, handle_input, &data);
	mlx_loop_hook(data.mlx_ptr, set_elements, &data);
	mlx_hook(data.mlx_win, DestroyNotify, 0, exit_game, &data);
	mlx_loop(data.mlx_ptr);
}
