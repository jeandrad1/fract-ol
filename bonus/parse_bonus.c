/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:09:38 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 13:20:49 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Function to set the fractal
// It set uses the argument to set the fractal name and constants
// If the name is not valid, it sets the error to -1
static void	set_fractal(t_fractol *f, int ac, char **av)
{
	if (ft_strncmp("Mandelbrot", av[1], 1) == 0)
		f->name = "M";
	else if (ft_strncmp("Julia", av[1], 1) == 0)
	{
		f->name = "J";
		if (ac > 2)
			set_julia_constants(f, ac, av);
		else
		{
			f->j_ci = -0.090000;
			f->j_cr = -0.766667;
		}
	}
	else if (ft_strncmp("Tricorn", av[1], 1) == 0)
		f->name = "T";
	else
		f->error = -1;
}

// Function to set the julia constants
// It uses the arguments to set the julia constants
// If the arguments are not valid, it sets the error to -1
// If there are no arguments, it sets the default values
static void	set_julia_constants(t_fractol *f, int ac, char **av)
{
	if (ac < 5 && ac != 3)
	{
		f->j_cr = ft_atof(av[2]);
		if (f->j_ci == -42 || f->j_ci > 2.0 || f->j_ci < -2.0)
			f->error = -1;
		f->j_ci = ft_atof(av[3]);
		if (f->j_cr == -42 || f->j_ci > 2.0 || f->j_ci < -2.0)
			f->error = -1;
	}
	else
		f->error = -1;
}

// Function to parse the arguments
// If there are less than 2 arguments, it sets the error to -1
// Otherwise, it sets the fractal
void	parse_args(int argc, char **argv, t_fractol *fractol)
{
	if (argc < 2)
		fractol->error = -1;
	else
	{
		set_fractal(fractol, argc, argv);
	}
}

