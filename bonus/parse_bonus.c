/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:09:38 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/11 19:52:01 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	set_fractal(t_fractol *f, int ac, char **av);
static void	set_julia_constants(t_fractol *f, int ac, char **av);

void	parse_args(int argc, char **argv, t_fractol *fractol)
{
	if (argc < 2)
		fractol->error = -1;
	else
	{
		set_fractal(fractol, argc, argv);
	}
}

static void	set_fractal(t_fractol *f, int ac, char **av)
{
	if (ft_strncmp("M", av[1], 1) == 0)
		f->name = "M";
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
	else if (ft_strncmp("T", av[1], 1) == 0)
		f->name = "T";
	else
		f->error = -1;
}

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
