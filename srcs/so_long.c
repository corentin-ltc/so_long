#include "../minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include "so_long.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\nWrong number of arguments.\n", 34);
		exit(1);
	}
	map_is_valid(argv[1]);
}