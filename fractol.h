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