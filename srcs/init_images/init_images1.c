/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:47:23 by cle-tort          #+#    #+#             */
/*   Updated: 2024/06/20 13:24:12 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/so_long.h"

void	free_and_exit(t_data *data)
{
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	freemap(data->map, 0, 1);
}

void	init_images1(t_data *data, t_game *game)
{
	int	x;
	int	y;

	game->im_wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"srcs/textures/wall.xpm", &x, &y);
	if (!game->im_wall)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		free_and_exit(data);
	}
	game->im_wall_shadow = mlx_xpm_file_to_image(data->mlx_ptr,
			"srcs/textures/wall_shadow.xpm", &x, &y);
	if (!game->im_wall_shadow)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		free_and_exit(data);
	}
}

void	init_images2(t_data *data, t_game *game)
{
	int	x;
	int	y;

	game->im_exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"srcs/textures/closed_chest.xpm", &x, &y);
	if (!game->im_exit)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_image(data->mlx_ptr, game->im_wall_shadow);
		free_and_exit(data);
	}
	game->im_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"srcs/textures/walterwhite.xpm", &x, &y);
	if (!game->im_player)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_image(data->mlx_ptr, game->im_wall_shadow);
		mlx_destroy_image(data->mlx_ptr, game->im_exit);
		free_and_exit(data);
	}
}

void	init_images3(t_data *data, t_game *game)
{
	int	x;
	int	y;

	game->im_coin_f1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"srcs/textures/coin_f1.xpm", &x, &y);
	if (!game->im_coin_f1)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_image(data->mlx_ptr, game->im_wall_shadow);
		mlx_destroy_image(data->mlx_ptr, game->im_exit);
		mlx_destroy_image(data->mlx_ptr, game->im_player);
		free_and_exit(data);
	}
}

void	init_images4(t_data *data, t_game *game)
{
	int	x;
	int	y;

	game->im_coin_f2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"srcs/textures/coin_f2.xpm", &x, &y);
	if (!game->im_coin_f2)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_image(data->mlx_ptr, game->im_wall_shadow);
		mlx_destroy_image(data->mlx_ptr, game->im_exit);
		mlx_destroy_image(data->mlx_ptr, game->im_player);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f1);
		free_and_exit(data);
	}
}
