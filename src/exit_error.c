/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:37:28 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 13:01:06 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Function to display the error message
// It receives an integer value with the error code
static void	error_parsing(int error)
{
	if (error == ARGS)
		printf("ERROR: Arguments error\n");
	if (error == MLX_FAIL)
		printf("ERROR: MLX error\n");
}

// Function to display the error message and exit the program
// After displaying the help information
int	exit_error(t_fractol *fractol, int error, int is_exit)
{
	error_parsing(error);
	(void) fractol;
	help_msg();
	if (is_exit)
		exit(error != NOTHING);
	return (error != NOTHING);
}
