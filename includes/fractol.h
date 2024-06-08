/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:10:39 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/08 11:10:50 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

# ifndef WIDTH
#  define WIDTH 1000
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# ifndef MAX_ITERATIONS
#  define MAX_ITERATIONS 100
# endif

typedef struct s_fractol
{
	t_img			img;
	char			*name;
	int				x;
	int				y;
	double			j_ci;
	double			j_cr;
	double			m_zi;
	double			m_zr;
	double			max_i;
	double			max_r;
	double			min_r;
	double			min_i;
	double			pi;
	double			pr;
	int				error;
	int				n;
	double			zoom_factor;
	t_color_scheme	cs;
}	t_fractol;

typedef struct s_img
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_img;

#endif