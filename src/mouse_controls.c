/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:09:48 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 12:27:23 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
