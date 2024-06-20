/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:29:00 by cle-tort          #+#    #+#             */
/*   Updated: 2024/06/20 13:29:30 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/so_long.h"

void	init_images5(t_data *data, t_game *game)
{
	int	x;
	int	y;

	game->im_coin_f3 = mlx_xpm_file_to_image(data->mlx_ptr,
			"srcs/textures/coin_f3.xpm", &x, &y);
	if (!game->im_coin_f3)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_image(data->mlx_ptr, game->im_wall_shadow);
		mlx_destroy_image(data->mlx_ptr, game->im_exit);
		mlx_destroy_image(data->mlx_ptr, game->im_player);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f1);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f2);
		free_and_exit(data);
	}
}

void	init_images6(t_data *data, t_game *game)
{
	int	x;
	int	y;

	game->im_coin_f4 = mlx_xpm_file_to_image(data->mlx_ptr,
			"srcs/textures/coin_f4.xpm", &x, &y);
	if (!game->im_coin_f4)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, game->im_wall);
		mlx_destroy_image(data->mlx_ptr, game->im_wall_shadow);
		mlx_destroy_image(data->mlx_ptr, game->im_exit);
		mlx_destroy_image(data->mlx_ptr, game->im_player);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f1);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f2);
		mlx_destroy_image(data->mlx_ptr, game->im_coin_f3);
		free_and_exit(data);
	}
}
