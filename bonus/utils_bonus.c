/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:09:28 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/29 13:12:24 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//Function to check if the character is a space
static int	is_space(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

//Function to skip the space and check if the number is negative
static int	skip_space(char *str, int *is_negative)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_negative *= -1;
		i++;
	}
	return (i);
}

// Function to convert a string to a double
// It retuns -42 if the string is not a number
double	ft_atof(char *str)
{
	int		i;
	int		is_negative;
	double	d;
	double	ret;

	is_negative = 1;
	d = 0.1;
	ret = 0.0;
	i = skip_space(str, &is_negative);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		ret = (ret * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		ret = ret + ((str[i] - '0') * d);
		d = d * 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-42);
	return (ret * is_negative);
}
