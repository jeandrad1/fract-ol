/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:37:28 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/23 17:18:59 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	free_fractol(t_fractol *fractol)
{
	if (fractol->img.mlx)
		free(fractol->img.mlx);
	if (fractol->img.img)
		free(fractol->img.img);
}

static void	error_parsing(int error)
{
	if (error == ARGS)
		printf("ERROR: Arguments error\n");
	if (error == MLX_FAIL)
		printf("ERRROR: MLX error\n");
}

int	exit_error(t_fractol *fractol, int error, int is_exit)
{
	error_parsing(error);
	free_fractol(fractol);
	help_msg();
	if (is_exit)
		exit(error != NOTHING);
	return (error != NOTHING);
}
