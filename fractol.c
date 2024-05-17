#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;
	t_img		img;

	img.mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	if (!img.img)
		return (1);
	fractol.img = img;
	parse_args(argc, argv, &fractol);
	if (fractol.error == -1)
	{
		help_msg();
		return (1);
	}
	help_msg();
	init(&fractol);
	draw_fractal(&fractol);
	mlx_scroll_hook(img.mlx, &handle_mouse, &fractol);
	mlx_key_hook(img.mlx, &handel_keyboard, &fractol);
	mlx_loop(fractol.img.mlx);
	mlx_terminate(fractol.img.mlx);
	return (EXIT_SUCCESS);
}