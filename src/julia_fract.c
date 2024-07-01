/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:10:06 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 12:55:01 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Function to calculate the Julia set
// It returns an integer value calculated by the formula
// Julia set: Z(n+1) = Z(n)^2 + C
// C = j_cr + j_ci
// Max iterations: 100
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
