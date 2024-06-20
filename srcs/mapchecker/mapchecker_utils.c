/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:06:40 by cle-tort          #+#    #+#             */
/*   Updated: 2024/06/20 14:09:22 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/so_long.h"

int	is_only_walls(char *line, bool is_first_line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '\n' )
		{
			if (is_first_line)
			{
				write(1, "Error: The map is not surrounded by walls.", 42);
				free(line);
				exit (1);
			}
			else
				return (0);
		}
		i++;
	}
	return (i);
}

void	initialize_struct(t_valid_map *map)
{
	map->width = 0;
	map->height = 0;
	map->has_a_floor = false;
	map->has_an_exit = false;
	map->nbr_of_items = 0;
	map->has_a_start = false;
}

void	display_error(char *line)
{
	if (line)
		free(line);
	write(1, "Error\nMap is not valid.\n", 24);
	exit(1);
}
