#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

# define WIDTH 800
# define HEIGHT 800

typedef struct s_complex
{
    double	re;
    double	im;
}	t_complex;

typedef struct image
{
    void	*img;
    char	*addr;
    int		bpp;
    int		line_length;
    int		endin;
}	t_image;

typedef struct		s_fractol
{
	void			*mlx;
	void			*window;
	t_image			*image;
	int				max_iteration;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
	int				start_line;
	int				finish_line;
	int				color_shift;
	int				(*formula)(struct s_fractol *fractol);
}					t_fractol;

//Para pruebas del makefile

int32_t main(void);

#endif