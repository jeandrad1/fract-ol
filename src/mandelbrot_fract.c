/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_fract.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:54:06 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/23 18:28:34 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot_set(t_fractol *f)
{
	int		n;
	double	temp;

	n = 0;
	f->m_zi = 0;
	f->m_zr = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((pow(f->m_zr, 2) + pow(f->m_zi, 2)) > 4)
			break ;
		temp = 2 * f->m_zr * f->m_zi + f->pi;
		f->m_zr = pow(f->m_zr, 2) - pow(f->m_zi, 2) + f->pr;
		f->m_zi = temp;
		n++;
	}
	return (n);
}
