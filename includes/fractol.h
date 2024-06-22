/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:10:39 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/22 11:43:09 by jeandrad         ###   ########.fr       */
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
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

# ifndef WIDTH
#  define WIDTH 1000
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# ifndef MAX_ITERATIONS
#  define MAX_ITERATIONS 100
# endif

typedef struct s_color_scheme
{
	int	shift;
	int	r_set;
	int	g_set;
	int	b_set;
	int	hue;
	int	saturation;
	int	brightness;
	int	contrast;
	int	c;
	int	x;
	int	m;
	int	r;
	int	g;
	int	b;
	int	palette;
}	t_color_scheme;

typedef struct s_img
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_img;

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

void		draw_fractal(t_fractol	*f);
int			julia_set(t_fractol *f);
int			mandelbrot_set(t_fractol *f);
void		init(t_fractol *fractol);
double		ft_atof(char *str);
void		help_msg(void);
void		parse_args(int argc, char **argv, t_fractol *fractol);
void		handle_mouse(double xdelta, double ydelta, void *param);
void		handle_keyboard(mlx_key_data_t key, void *param);
void		zoom(t_fractol *fractol, int x, int y, double zoom_factor);
void		set_screen_size(t_fractol *f);
int			get_psychedelic_color(t_fractol *f);
int			tricorn_set(t_fractol *f);
void		move(t_fractol *f, double distance, char direction);
int			shift_color(t_color_scheme *cs);

#endif