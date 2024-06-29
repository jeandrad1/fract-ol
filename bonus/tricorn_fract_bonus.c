/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_fract_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:41:30 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 13:18:38 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Function to set the tricorn fractal
// The formula is Z = conjugate(Z)^2 + Z(0) 
// Z(0) = 0 
int	tricorn_set(t_fractol *f)
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
		temp = 2 * f->m_zr * (-f->m_zi) + f->pi;
		f->m_zr = pow(f->m_zr, 2) - pow(f->m_zi, 2) + f->pr;
		f->m_zi = temp;
		n++;
	}
	return (n);
}
