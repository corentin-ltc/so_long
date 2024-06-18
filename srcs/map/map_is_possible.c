/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_possible.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:41:14 by cle-tort          #+#    #+#             */
/*   Updated: 2024/06/18 21:15:55 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


int	path_finder(char **map, int y, int x, t_valid_map *map_info)
{
	static int	items = 0;

	if (map[y][x] == 'E' && items == map_info->nbr_of_items)
		return (1);
	
	
}
char	**map_is_possible(char *file, t_valid_map *map_info)
{
	int		fd;
	int		sz;
	char	**map;
	char	*brut_map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		display_error(0);
	brut_map = malloc(sizeof(char) * (map_info->width * (map_info->height + 1)));
	if (!brut_map)
		display_error(0);
	sz = read(fd, brut_map, (map_info->width * (map_info->height + 1)));
	if (sz < 0)
	{
		free(brut_map);
		display_error(0);
	}
	brut_map[sz] = 0;
	map = ft_split(brut_map, '\n');
	free(brut_map);
	if (!map)
		display_error(0);
	path_finder(map, 0, 0, map_info);
}

int main(void)
{
	char **map;

	map = map_is_possible("test.ber", 13, 6, 4);

	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 13;  x++)
		{
			printf("%c", map[y][x]);
		}
		printf("\n");
	}
}