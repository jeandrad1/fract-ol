/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_mayus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:31:33 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/08 17:39:44 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex_mayus(unsigned int n)
{
	char	*hex;
	int		i;
	int		count;

	hex = "0123456789ABCDEF";
	i = 0;
	count = 0;
	if (n >= 16)
		count += ft_print_hex_mayus(n / 16);
	ft_putchar(hex[n % 16]);
	count++;
	return (count);
}
