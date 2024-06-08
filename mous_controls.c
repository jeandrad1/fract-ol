#include "../../includes/fractol.h"

void	handle_mouse(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;
	int32_t		mouse_x;
	int32_t		mouse_y;

	(void)xdelta;
	fractol = (t_fractol *)param;
	mlx_get_mouse_pos(fractol->img.mlx, &mouse_x, &mouse_y);
	if (ydelta < 0)
		zoom(fractol, mouse_x, mouse_y, fractol->zoom_factor);
	else if (ydelta > 0)
		zoom(fractol, mouse_x, mouse_y, 1 / fractol->zoom_factor);
	draw_fractal(fractol);
}