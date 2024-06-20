
#include "so_long.h"

void	move_up(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P' && y > 1 && data->map[y - 1][x] != '1')
			{
				++data->movements_count;
				if (data->map[y - 1][x] == 'C')
					data->map_info->items_collected++;
				data->map[y][x] = '0';
				data->map[y - 1][x] = 'P';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_down(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P' && y < data->map_info->height - 2 && data->map[y + 1][x] != '1')
			{
				++data->movements_count;
				if (data->map[y + 1][x] == 'C')
					data->map_info->items_collected++;
				data->map[y][x] = '0';
				data->map[y + 1][x] = 'P';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_left(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P' && x > 1 && data->map[y][x - 1] != '1')
			{
				++data->movements_count;
				if (data->map[y][x - 1] == 'C')
					data->map_info->items_collected++;
				data->map[y][x] = '0';
				data->map[y][x - 1] = 'P';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_right(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P' && x < data->map_info->width - 2 && data->map[y][x + 1] != '1')
			{
				++data->movements_count;
				if (data->map[y][x + 1] == 'C')
					data->map_info->items_collected++;
				data->map[y][x] = '0';
				data->map[y][x + 1] = 'P';
				return ;
			}
			x++;
		}
		y++;
	}
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		exit_game(data);
	if (keysym == XK_w)
	 	move_up(data);
	else if (keysym == XK_s)
	 	move_down(data);
	else if (keysym == XK_a)
	 	move_left(data);
	else if (keysym == XK_d)
	 	move_right(data);
	return (0);
}