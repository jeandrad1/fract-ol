/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:09:48 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 12:47:52 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Function to zoom in or out
// This function sets constants to zoom in or out
// in the middle of the image
// Zoom factor is 1.5
// It will zoom in if the mouse wheel is down
// It will zoom out if the mouse wheel is up
void	handle_mouse(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;
	const int	zoom_x = 500;
	const int	zoom_y = 500;

	(void)xdelta;
	fractol = (t_fractol *)param;
	if (ydelta < 0)
		zoom(fractol, zoom_x, zoom_y, fractol->zoom_factor);
	else if (ydelta > 0)
		zoom(fractol, zoom_x, zoom_y, 1 / fractol->zoom_factor);
	draw_fractal(fractol);
}
