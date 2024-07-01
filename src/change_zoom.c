/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:11:25 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 13:07:03 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Function to zoom in or out
// It receives the fractol structure, the x and y values, the zoom factor
// It calculates the new values
// It sets the new values 
void	zoom(t_fractol *fractol, int x, int y, double zoom_factor)
{
	double	x_math;
	double	y_math;
	double	new_x_range;
	double	new_y_range;

	x_math = fractol->min_r + ((double)x / WIDTH)
		* (fractol->max_r - fractol->min_r);
	y_math = fractol->min_i + (1 - (double)y / HEIGHT)
		* (fractol->max_i - fractol->min_i);
	new_x_range = (fractol->max_r - fractol->min_r) / zoom_factor;
	new_y_range = (fractol->max_i - fractol->min_i) / zoom_factor;
	fractol->min_r = x_math - ((double)x / WIDTH) * new_x_range;
	fractol->max_r = fractol->min_r + new_x_range;
	fractol->min_i = y_math - (1 - (double)y / HEIGHT) * new_y_range;
	fractol->max_i = fractol->min_i + new_y_range;
}
