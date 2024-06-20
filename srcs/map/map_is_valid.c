/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:48:14 by cle-tort          #+#    #+#             */
/*   Updated: 2024/06/20 07:51:11 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	analyze_line2(t_valid_map *map)
{
	int	i;

	i = 0;
	while (map->line[i] && !map->has_a_floor)
	{
		if (map->line[i] != '1' && map->line[i] != '0' && map->line[i] != 'C' && map->line[i] != 'E' && map->line[i] != 'P' &&  map->line[i] != '\n')
		 	display_error(map->line);
		if ((i == 0 || i == map->width - 1) && map->line[i] != '1')
			display_error(map->line);
		if (map->line[i] == 'E')
		{
			if (map->has_an_exit)
				display_error(map->line);
			map->has_an_exit = true;
		}
		if (map->line[i] == 'C')
			map->nbr_of_items++;
		if (map->line[i] == 'P')
		{
			if (map->has_a_start)
				display_error(map->line);
			map->has_a_start = true;
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
	while(map->line[i])
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
	if (map->height > 15 || map->width > 25 || !map->has_a_start || !map->has_an_exit || !map->nbr_of_items || !map->has_a_floor)
		display_error(0);
}

char	**map_is_valid(char *file, t_valid_map *map)
{
	int	fd;

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
			break;
		map->height++;
		analyze_line(map);
		free(map->line);
	}
	map_validator(map);
	close(fd);
	return(map_is_possible(file, map));
}
