/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:10:00 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 12:52:00 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Function to exit the program
// It deletes the image and closes the window
// It terminates the mlx
// It exits the program with EXIT_SUCCESS
// Used for error handling
static void	exit_mlx(t_img *img)
{
	mlx_delete_image(img->mlx, img->img);
	mlx_close_window(img->mlx);
	mlx_terminate(img->mlx);
	exit(EXIT_SUCCESS);
}

// Function to handle keyboard events
// It receives a key and a parameter
// It checks if the key is the escape key
// If it is, it calls the exit_mlx function
// If it is not, it returns
void	handle_keyboard(mlx_key_data_t key, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (key.key == MLX_KEY_ESCAPE)
	{
		exit_mlx(&fractol->img);
		return ;
	}
	else
		return ;
	draw_fractal(fractol);
}
