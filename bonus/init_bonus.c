/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:10:15 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 13:25:28 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Function to set the screen size
// If the fractal is Julia, the screen size is set to 2.0
// Else, the screen size is set to 4.0
void	set_screen_size(t_fractol *f)
{
	if (ft_strncmp("Julia", f->name, 1) == 0)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = 2.0;
	}
	else
	{
		f->min_r = -4.0;
		f->max_r = 4.0;
		f->min_i = -4.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
}

// Function to initialize the color scheme
// It sets the shift to -999
// It sets contrast to 100
// It sets the rest to 0
static void	init_cs(t_color_scheme *cs)
{
	cs->shift = -999;
	cs->contrast = 100;
	cs->r_set = 0;
	cs->g_set = 0;
	cs->b_set = 0;
	cs->hue = 0;
	cs->saturation = 0;
	cs->brightness = 0;
	cs->c = 0;
	cs->x = 0;
	cs->m = 0;
	cs->r = 0;
	cs->g = 0;
	cs->b = 0;
	cs->palette = 0;
}

// Function to initialize the fractol structure
// It sets the zoom factor to 1.5
// It sets the rest to 0
void	init(t_fractol *fractol)
{
	fractol->zoom_factor = 1.5;
	fractol->x = 0;
	fractol->y = 0;
	fractol->max_i = 0;
	fractol->max_r = 0;
	fractol->min_i = 0;
	fractol->min_r = 0;
	fractol->pi = 0;
	fractol->pr = 0;
	fractol->m_zi = 0;
	fractol->m_zr = 0;
	fractol->error = 0;
	fractol->n = 0;
	set_screen_size(fractol);
	init_cs(&fractol->cs);
}
