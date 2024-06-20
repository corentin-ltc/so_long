/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:59:39 by cle-tort          #+#    #+#             */
/*   Updated: 2024/06/20 13:28:29 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/so_long.h"

void	init_images7(t_data *data, t_game *game)
{
	int	x;
	int	y;

	game->im_coin_f5 = mlx_xpm_file_to_image(data->mlx_ptr,
			"srcs/textures/coin_f5.xpm", &x, &y);
	if (!game->im_coin_f5)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_image(data->mlx_ptr, game->im_wall_shadow);
		mlx_destroy_image(data->mlx_ptr, game->im_exit);
		mlx_destroy_image(data->mlx_ptr, game->im_player);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f1);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f2);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f3);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f4);
		free_and_exit(data);
	}
}

void	init_images8(t_data *data, t_game *game)
{
	int	x;
	int	y;

	game->im_floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"srcs/textures/floor.xpm", &x, &y);
	if (!game->im_floor)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_image(data->mlx_ptr, game->im_wall_shadow);
		mlx_destroy_image(data->mlx_ptr, game->im_exit);
		mlx_destroy_image(data->mlx_ptr, game->im_player);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f1);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f2);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f3);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f4);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f5);
		free_and_exit(data);
	}
}

void	init_images(t_data *data, t_game *game, char **map)
{
	init_images1(data, game);
	init_images2(data, game);
	init_images3(data, game);
	init_images4(data, game);
	init_images5(data, game);
	init_images6(data, game);
	init_images7(data, game);
	init_images8(data, game);
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

int	exit_game(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free_images(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	freemap(data->map, 0, 3);
}
