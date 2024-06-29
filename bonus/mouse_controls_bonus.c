/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:09:48 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 13:21:19 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Function to handle the mouse
// It uses mlx functions to get the mouse position
// It zooms in or out depending on the mouse wheel and the mouse position
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
