/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:10:24 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/11 19:52:18 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	help_msg(void)
{
	ft_printf("⊱ ───────────────── {.⋅ Fractol ⋅.} ───────────────── ⊰\n\n");
	ft_printf("Which fractal would you like to see?\n");
	ft_printf("J - Julia    ");
	ft_printf("\n\n");
	ft_printf("\e[36mUsage example:\t./fractol <type>\n\t\t./fractol M\e[0m\n\n"\
	);
	ft_printf("\nFor Julia, you may specify starting values which should be betw\
	een -2.0 and 2.0.\n");
	ft_printf("\e[36mUsage example:\t");
	ft_printf("./fractol J\n\t\t./fractol J 0.285 0.01\n");
	ft_printf("\t\t./fractol J -0.4 0.6\n");
	ft_printf("\t\t./fractol J -1.476 0.0\n");
	ft_printf("\t\t./fractol J 0.3 -0.01\e[0m\n\n");
}
