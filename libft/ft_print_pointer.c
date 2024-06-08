/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:35:14 by jeandrad          #+#    #+#             */
/*   Updated: 2024/06/08 17:40:21 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int	ft_print_pointer(void *p)
{
	int	count;
	int	aux;

	aux = p;
	ft_print_str("0x");
	count = 2;
	if (aux >= 16)
		count += ft_print_pointer(aux / 16);
	ft_putchar("0123456789abcdef"[aux % 16]);
	count++;
	return (count);
}
*/

static long long int	ft_ptr_len(unsigned long long num)
{
	unsigned long long	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_ptr(unsigned long long  num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	unsigned long long	print_length;
	
	print_length = 0;
	if (ptr < 0)
		return (-1);
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}
