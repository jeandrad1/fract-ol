/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:34:21 by jeandrad          #+#    #+#             */
/*   Updated: 2024/01/10 12:52:04 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	long int	nb;
	int count;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		count++;
	}
	if (nb >= 10)
	{
		ft_print_int(nb / 10);
		ft_print_int(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}
