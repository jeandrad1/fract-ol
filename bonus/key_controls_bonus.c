/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:10:00 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 13:23:14 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Function to exit the mlx
// It deletes the image and closes the window
// It terminates the mlx
// It exits with success
static void	exit_mlx(t_img *img)
{
	mlx_delete_image(img->mlx, img->img);
	mlx_close_window(img->mlx);
	mlx_terminate(img->mlx);
	exit(EXIT_SUCCESS);
}

// Function to handle the keyboard
// It receives the key and the param
// It handles the ESC key to exit the mlx
// And the arrow keys to move the fractal with the move function
void	handle_keyboard(mlx_key_data_t key, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (key.key == MLX_KEY_ESCAPE)
	{
		exit_mlx(&fractol->img);
		return ;
	}
	else if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
		move(fractol, 0.2, 'U');
	else if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
		move(fractol, 0.2, 'D');
	else if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
		move(fractol, 0.2, 'L');
	else if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
		move(fractol, 0.2, 'R');
	else if (key.key == MLX_KEY_SPACE && key.action == MLX_PRESS)
		shift_color(&fractol->cs);
	else
		return ;
	draw_fractal(fractol);
}
