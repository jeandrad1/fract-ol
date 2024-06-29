/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:09:38 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 12:27:06 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	set_julia_constants(t_fractol *f, int ac, char **av)
{
	double	temp_j_cr;
	double	temp_j_ci;

	if (ac < 5 && ac != 3)
	{
		temp_j_cr = ft_atof(av[2]);
		temp_j_ci = ft_atof(av[3]);
		if (temp_j_cr == -42 || temp_j_cr > 2.0 || temp_j_cr < -2.0)
			f->error = -1;
		else
			f->j_cr = temp_j_cr;
		if (temp_j_ci == -42 || temp_j_ci > 2.0 || temp_j_ci < -2.0)
			f->error = -1;
		else
			f->j_ci = temp_j_ci;
	}
	else
		f->error = -1;
}

static void	set_mandelbrot_constants(t_fractol *f, int ac, char **av)
{
	if (ac == 4)
	{
		f->m_zr = ft_atof(av[2]);
		f->m_zi = ft_atof(av[3]);
		if ((pow(f->m_zr, 2) + pow(f->m_zi, 2)) > 4.0)
			f->error = -1;
	}
	else
		f->error = -1;
}

static void	set_fractal(t_fractol *f, int ac, char **av)
{
	if (ft_strncmp("Mandelbrot", av[1], 10) == 0)
	{
		f->name = "Mandelbrot";
		if (ac > 2)
			set_mandelbrot_constants(f, ac, av);
		else
		{
			f->m_zi = 0;
			f->m_zr = 0;
		}
	}
	else if (ft_strncmp("Julia", av[1], 5) == 0)
	{
		f->name = "Julia";
		if (ac > 2)
			set_julia_constants(f, ac, av);
		else
		{
			f->j_ci = -0.090000;
			f->j_cr = -0.766667;
		}
	}
	else
		f->error = -1;
}

void	parse_args(int argc, char **argv, t_fractol *fractol)
{
	if (argc < 2)
		fractol->error = -1;
	else
	{
		set_fractal(fractol, argc, argv);
	}
}
