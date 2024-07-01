/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fract_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:10:06 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 13:23:33 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Function to set the julia fractal
// The formula is Z = Z^2 + C
// C is a constant
// C = f->j_cr + f->j_ci
int	julia_set(t_fractol *f)
{
	int		n;
	double	temp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((f->pi * f->pi + f->pr * f->pr) > 4.0)
			break ;
		temp = 2 * f->pr * f->pi + f->j_ci;
		f->pr = f->pr * f->pr - f->pi * f->pi + f->j_cr;
		f->pi = temp;
		n++;
	}
	return (n);
}
