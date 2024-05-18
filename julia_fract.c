/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:50:52 by jeandrad          #+#    #+#             */
/*   Updated: 2024/05/18 11:50:52 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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