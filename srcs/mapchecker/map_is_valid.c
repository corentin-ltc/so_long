/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:48:14 by cle-tort          #+#    #+#             */
/*   Updated: 2024/06/20 14:11:37 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/so_long.h"

void	analyze_line2(t_valid_map *map)
{
	int	i;

	i = 0;
	while (map->line[i] && !map->has_a_floor)
	{
		if (map->line[i] != '1' && map->line[i] != '0' && map->line[i] != 'C'
			&& map->line[i] != 'E' && map->line[i] != 'P'
			&& map->line[i] != '\n')
			display_error(map->line);
		if ((i == 0 || i == map->width - 1) && map->line[i] != '1')
			display_error(map->line);
		if (map->line[i] == 'E')
		{
			if (map->has_an_exit++)
				display_error(map->line);
		}
		if (map->line[i] == 'C')
			map->nbr_of_items++;
		if (map->line[i] == 'P')
		{
			if (map->has_a_start++)
				display_error(map->line);
		}
		i++;
	}
}

void	analyze_line(t_valid_map *map)
{
	int	i;

	if (ft_strlen(map->line) != map->width)
		display_error(map->line);
	if (map->has_a_floor)
		display_error(map->line);
	i = 0;
	while (map->line[i])
	{
		if (map->line[i] == 'P')
		{
			map->spawn_x = i;
			map->spawn_y = map->height - 1;
		}
		i++;
	}
	if (is_only_walls(map->line, 0))
		map->has_a_floor = true;
	analyze_line2(map);
}

void	map_validator(t_valid_map *map)
{
	if (map->height > 15 || map->width > 25 || !map->has_a_start
		|| !map->has_an_exit || !map->nbr_of_items || !map->has_a_floor)
		display_error(0);
}

void	check_is_ber(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 5)
	{
		write(1, "Error\nMap is not a .ber file.\n", 30);
		exit(1);
	}
	if (file[i - 4] != '.' || file[i - 3] != 'b'
		|| file[i - 2] != 'e' || file[i - 1] != 'r')
	{
		write(1, "Error\nMap is not a .ber file.\n", 30);
		exit(1);
	}
}

char	**map_is_valid(char *file, t_valid_map *map)
{
	int	fd;

	check_is_ber(file);
	initialize_struct(map);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		display_error(0);
	map->line = get_next_line(fd);
	if (!map->line)
		display_error(0);
	map->height = 1;
	map->width = is_only_walls(map->line, 1);
	free(map->line);
	while (map->line)
	{
		map->line = get_next_line(fd);
		if (!map->line)
			break ;
		map->height++;
		analyze_line(map);
		free(map->line);
	}
	map_validator(map);
	close(fd);
	return (map_is_possible(file, map));
}
