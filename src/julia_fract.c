/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:10:06 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/23 17:31:52 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia_set(t_fractol *f)
{
	int		n;
	double	temp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((pow(f->pi, 2) + pow(f->pr, 2)) > 4.0)
			break ;
		temp = 2 * f->pr * f->pi + f->j_ci;
		f->pr = pow(f->pr, 2) - pow(f->pi, 2) + f->j_cr;
		f->pi = temp;
		n++;
	}
	return (n);
}
