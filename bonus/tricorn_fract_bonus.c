/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon_fract_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:41:30 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/24 18:13:31 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
int	burning_ship_set(t_fractol *f)
{
	int		n;
	double	temp;

	n = 0;
	f->m_zi = 0;
	f->m_zr = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((f->m_zr * f->m_zr + f->m_zi * f->m_zi) > 4)
			break ;
		temp = 2 * fabs(f->m_zr) * fabs(f->m_zi) + f->pi;
		f->m_zr = f->m_zr * f->m_zr - f->m_zi * f->m_zi + f->pr;
		f->m_zi = temp;
		n++;
	}
	return (n);
}
*/
int	tricorn_set(t_fractol *f)
{
	int		n;
	double	temp;

	n = 0;
	f->m_zi = 0;
	f->m_zr = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((f->m_zr * f->m_zr + f->m_zi * f->m_zi) > 4)
			break ;
		temp = 2 * f->m_zr * (-f->m_zi) + f->pi;
		f->m_zr = f->m_zr * f->m_zr - f->m_zi * f->m_zi + f->pr;
		f->m_zi = temp;
		n++;
	}
	return (n);
}
