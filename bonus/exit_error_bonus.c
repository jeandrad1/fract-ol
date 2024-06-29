/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:37:28 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 13:29:45 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Function to display the error message
// It uses the error code to display the error message
static void	error_parsing(int error)
{
	if (error == ARGS)
		printf("ERROR: Arguments error\n");
	if (error == MLX_FAIL)
		printf("ERRROR: MLX error\n");
}

// Function exit_error
// It displays the error message and the help message
// It exits the program
// Used for error handling
int	exit_error(t_fractol *fractol, int error, int is_exit)
{
	error_parsing(error);
	(void) fractol;
	help_msg();
	if (is_exit)
		exit(error != NOTHING);
	return (error != NOTHING);
}
