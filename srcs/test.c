#include "../minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include "so_long.h"

#define SIDE_LEN 960

void	exit_program(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(1);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int offset;
	
	offset = (img->line_len * y) + (x * (img->bits_per_pixels / 8));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color; 
}

void	color_screen(t_data *data, int color)
{
	for (int y = 0; y < SIDE_LEN; ++y)
	{
		for (int x = 0; x < SIDE_LEN; ++x)
		{
			my_pixel_put(&data->img, x, y, color);
		}
	}
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		exit_program(data);
	if (keysym == XK_r)
		color_screen(data, 0xff0000);
	if (keysym == XK_g)
		color_screen(data, 0xff00);
	if (keysym == XK_b)
		color_screen(data, 0xff);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0, 0);
	printf("Key number = %d\n", keysym);
	return (0);
}

void	*send_address(void *mlx, void *win, int getOne)
{
	static void	*mlx_ptr;
	static void	*mlx_win;
	
	if (!getOne)
	{
		mlx_ptr = mlx;
		mlx_win = win;
	}
	if (getOne == 1)
		return (mlx_ptr);
	else if (getOne == 2)
		return (mlx_win);
}

int	receive_coords(int x, int y, void *p)
{
	t_data	data2;
	void	*mlx;
	void	*win;

	mlx = send_address(0, 0, 1);
	win = send_address(0, 0, 2);
	mlx_pixel_put(mlx, win, x, y, 0xff);
}

int main(void)
{
	t_data	data;
	char	*data2;

	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (1);
	 if ((data.mlx_win = mlx_new_window(data.mlx_ptr, SIDE_LEN, SIDE_LEN, "Mini Paint")) == NULL)
	 {
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
	 	return (1);
	 }
	send_address(data.mlx_ptr, data.mlx_win, 0);
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, SIDE_LEN, SIDE_LEN);
	data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixels, &data.img.line_len, &data.img.endian);

	int bpp;
	int sl;
	int endian;
	int x;
	int y;
	void *im;

	if(!(im = mlx_xpm_file_to_image(data.mlx_ptr, "wall.xpm", &x, &y)))
	{
		printf("im = %p", im);
     	 	printf(" !! KO !!\n");
     		exit(1);
    	}
	data2 = mlx_get_data_addr(im, &bpp, &sl, &endian);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, im, 0, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, im, 64, 0);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, im, 128, 0);



//	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, im, 100, 100);
//	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, im, 500, 500);

//	mlx_key_hook(data.mlx_win, handle_input, &data);
//	mlx_hook(data.mlx_win, MotionNotify, PointerMotionMask, receive_coords, 0);
	mlx_loop(data.mlx_ptr);
}