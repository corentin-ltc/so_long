/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_possible.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:41:14 by cle-tort          #+#    #+#             */
/*   Updated: 2024/06/21 01:48:17 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/so_long.h"

int	path_finder(t_pathfinder *pathfinder, int y, int x, t_valid_map *map_info)
{
	static int	items = 0;

	if (pathfinder->map[y][x] == 'E' && items == map_info->nbr_of_items)
		return (1);
	if (pathfinder->map[y][x] == '1' || pathfinder->visited[y][x] == 'V')
		return (0);
	if (pathfinder->map[y][x] == 'C' && pathfinder->visited[y][x] != 'V')
		items++;
	pathfinder->visited[y][x] = 'V';
	if (path_finder(pathfinder, y - 1, x, map_info)
		|| path_finder(pathfinder, y + 1, x, map_info))
		return (1);
	if (path_finder(pathfinder, y, x + 1, map_info)
		|| path_finder(pathfinder, y, x - 1, map_info))
		return (1);
	return (0);
}

void	freemap(char **split, char **split2, int display_error)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
	i = 0;
	if (split2)
	{
		while (split2[i])
			free(split2[i++]);
		free(split2);
	}
	if (display_error == 1)
		write(1, "Error\nSomething went wrong.", 27);
	else if (display_error == 2)
		write(1, "Error\nMap is not possible.", 26);
	if (display_error)
		exit(1);
}

char	**map_is_possible(char *file, t_valid_map *map_info)
{
	t_pathfinder	pathfinder;

	pathfinder.fd = open(file, O_RDONLY);
	if (pathfinder.fd == -1)
		display_error(0);
	pathfinder.brut_map = malloc(sizeof(char)
			*(map_info->width * (map_info->height + 1)));
	if (!pathfinder.brut_map)
		display_error(0);
	pathfinder.sz = read(pathfinder.fd, pathfinder.brut_map,
			(map_info->width * (map_info->height + 1)));
	if (pathfinder.sz < 0)
		display_error(pathfinder.brut_map);
	pathfinder.brut_map[pathfinder.sz] = 0;
	pathfinder.map = ft_split(pathfinder.brut_map, '\n');
	pathfinder.visited = ft_split(pathfinder.brut_map, '\n');
	free(pathfinder.brut_map);
	if (!pathfinder.visited || !pathfinder.map)
		freemap(pathfinder.map, pathfinder.visited, 1);
	if (!(path_finder(&pathfinder, map_info->spawn_y,
				map_info->spawn_x, map_info)))
		freemap(pathfinder.visited, pathfinder.map, 2);
	freemap(pathfinder.visited, 0, 0);
	map_info->items_collected = 0;
	return (pathfinder.map);
}
