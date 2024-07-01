/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:11:12 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 13:05:49 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Function to get the color
// It receives the red, green, blue and alpha values
// It returns the color in hexadecimal
static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// Function to get the absolute value
static int	absolute(int a)
{
	if (a < 0)
		return (a * (-1));
	return (a);
}

// Function to set the upper values of the RGB
// It sets the red, green and blue values
// It returns 1 if the hue is less than 60 or 120 or 180
// It changes the values of the red, green and blue
static int	set_rgb_upper(t_color_scheme *cs)
{
	if (cs->hue < 60)
	{
		cs->r = cs->c;
		cs->g = cs->x;
		cs->b = 0;
		return (1);
	}
	else if (cs->hue < 120)
	{
		cs->r = cs->x;
		cs->g = cs->c;
		cs->b = 0;
		return (1);
	}
	else if (cs->hue < 180)
	{
		cs->r = 0;
		cs->g = cs->c;
		cs->b = cs->x;
		return (1);
	}
	return (0);
}

static void	set_rgb(t_color_scheme *cs)
{
	if (set_rgb_upper(cs))
		return ;
	else if (cs->hue < 240)
	{
		cs->r = 0;
		cs->g = cs->x;
		cs->b = cs->c;
	}
	else if (cs->hue < 300)
	{
		cs->r = cs->x;
		cs->g = 0;
		cs->b = cs->c;
	}
	else
	{
		cs->r = cs->c;
		cs->g = 0;
		cs->b = cs->x;
	}
}

int	get_psychedelic_color(t_fractol *f)
{
	if (f->n == MAX_ITERATIONS)
		return (get_rgba(0, 0, 0, 255));
	f->cs.hue = (f->n * 360) / f->cs.contrast + f->cs.shift * 2;
	f->cs.saturation = (f->n * 255) / f->cs.contrast;
	f->cs.brightness = (f->n * 255) / f->cs.contrast;
	f->cs.c = (255 - absolute(2 * f->cs.brightness - 255)) * f->cs.saturation / \
	255;
	f->cs.x = f->cs.c * (1 - absolute((f->cs.hue / 60) % 2 - 1));
	f->cs.m = f->cs.brightness - f->cs.c / 2;
	set_rgb(&f->cs);
	return (get_rgba(f->cs.r + f->cs.m, f->cs.g + f->cs.m, f->cs.b + f->cs.m, \
	255));
}
