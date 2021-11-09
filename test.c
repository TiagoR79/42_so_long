#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_vars {
    void *mlx;
    void *window;
}               t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void create_triangle(t_data address)
{
    int x = 0;
    int y = 0;

    while (x <= 10)
        my_mlx_pixel_put(&address, x++, y++, 0x00FF0000);
    while(y >= 0)
        my_mlx_pixel_put(&address, x++, y--, 0x00FF0000);
    x -= 1;
    while(x >= 1)
        my_mlx_pixel_put(&address, x--, 0, 0x00FF0000);
}

int	ft_close(int keycode, t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->window);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == 53 || keycode == 27)
	{
    	mlx_destroy_window(vars->mlx, vars->window);
		exit(0);
	}
}

int mouse_hook(int button, int x, int y, void *param)
{
	printf("%d\n", button);
}

int	main(void)
{
    t_vars vars;

    //images
	t_data	img;
    t_data  triangle;

	// inits the mlx pointer and window
	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, 600, 300, "Hello world!");

	//creates a new imgage and gives it a address
	img.img = mlx_new_image(vars.mlx, 600, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    triangle.img = mlx_new_image(vars.mlx, 600, 300);
	triangle.addr = mlx_get_data_addr(triangle.img, &triangle.bits_per_pixel, &triangle.line_length, &triangle.endian);

    create_triangle(triangle);

	mlx_put_image_to_window(vars.mlx, vars.window, triangle.img, 20, 20);


	//handles key strokes
	mlx_key_hook(vars.window, key_hook, &vars);
	//handles mouse key strokes
	mlx_mouse_hook(vars.window, &mouse_hook, 0);

	// when press (x) program exits --> handle the segfault
	mlx_hook(vars.window, 17, 1L<<17, ft_close, &vars);

	mlx_loop(vars.mlx);
}
