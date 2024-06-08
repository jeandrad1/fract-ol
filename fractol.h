#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
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

typedef struct s_complex
{
    double	re;
    double	im;
}	t_complex;
typedef struct s_img
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_img;

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

double	ft_atof(char *str);
int	get_psychedelic_color(t_fractol *f)
void	draw_fractal(t_fractol	*f)
static void	set_julia_constants(t_fractol *f, int ac, char **av)
void	handle_keyboard(mlx_key_data_t key, void *param)
int	julia_set(t_fractol *f)

