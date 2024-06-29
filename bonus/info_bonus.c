/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:10:24 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 12:27:42 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	help_msg(void)
{
	ft_printf("\nFractol\n\n");
	ft_printf("Fractals avaliable:\n");
	ft_printf("Julia\n");
	ft_printf("Mandelbrot\n");
	ft_printf("Tricorn\n");
	ft_printf("\n\n");
	ft_printf("Usage example:\t./fractol <type>\n\t\t");
	ft_printf("\nFor Julia, you may specify starting values which should be betw\
	een -2.0 and 2.0.\n");
	ft_printf("Interesting examples:\t");
	ft_printf("./fractol Julia\n\t\t./fractol Julia 0.285 0.01\n");
	ft_printf("\t\t./fractol Julia -0.4 0.6\n");
	ft_printf("\t\t./fractol Julia -1.476 0.0\n");
	ft_printf("\t\t./fractol Julia 0.3 -0.01\n\n");
}
