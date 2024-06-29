/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:11:00 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 13:27:51 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Main function of the program
// It initializes the fractol structure
// It parses the arguments
// It initializes the image
// It displays the help message
// It draws the fractal
// Catches the mouse and keyboard events with mlx42 functions
// It loops the mlx42
// It terminates the mlx42
// It returns 0
int	main(int argc, char **argv)
{
	t_fractol	fractol;
	t_img		img;

	ft_memset(&fractol, 0, sizeof(t_fractol));
	parse_args(argc, argv, &fractol);
	if (fractol.error == -1)
		exit_error(&fractol, ARGS, 1);
	img.mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	if (!img.img)
	{
		mlx_terminate(img.mlx);
		exit_error(&fractol, MLX_FAIL, 0);
	}
	fractol.img = img;
	help_msg();
	init(&fractol);
	draw_fractal(&fractol);
	mlx_scroll_hook(img.mlx, &handle_mouse, &fractol);
	mlx_key_hook(img.mlx, &handle_keyboard, &fractol);
	mlx_loop(fractol.img.mlx);
	mlx_terminate(fractol.img.mlx);
	return (EXIT_FAILURE);
}
