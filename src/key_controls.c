/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:10:00 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/23 18:11:36 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	exit_mlx(t_img *img)
{
	mlx_delete_image(img->mlx, img->img);
	mlx_close_window(img->mlx);
	mlx_terminate(img->mlx);
	exit(EXIT_SUCCESS);
}

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
