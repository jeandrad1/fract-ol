/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:09:38 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/15 13:31:10 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

static void	set_mandelbrot_constants(t_fractol *f, int ac, char **av)
{
	if (ac < 5 && ac != 3)
	{
		f->m_zr = ft_atof(av[2]);
		if (f->m_zr == -42 || f->m_zr > 2.0 || f->m_zr < -2.0)
			f->error = -1;
		f->m_zi = ft_atof(av[3]);
		if (f->m_zi == -42 || f->m_zi > 2.0 || f->m_zi < -2.0)
			f->error = -1;
	}
	else
		f->error = -1;
}


static void	set_fractal(t_fractol *f, int ac, char **av)
{
	if (ft_strncmp("M", av[1], 1) == 0)
	{
		f->name = "M";
		if (ac > 2)
			set_mandelbrot_constants(f, ac, av);
		else
		{
			f->m_zi = 0;
			f->m_zr = 0;
		}
	}
	else if (ft_strncmp("J", av[1], 1) == 0)
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
