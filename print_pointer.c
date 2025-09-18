/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:59:48 by ikhanenk          #+#    #+#             */
/*   Updated: 2024/09/09 13:51:53 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_pointer(unsigned long p)
{
	char	ch;
	char	*radix;
	int		len;

	len = 0;
	radix = "0123456789abcdef";
	if (p >= 16)
	{
		len += ft_print_pointer(p / 16);
		len += ft_print_pointer(p % 16);
	}
	else
	{
		ch = radix[p];
		len += 1;
		write(1, &ch, 1);
	}
	return (len);
}

int	print_pointer(unsigned long p, int *i)
{
	int		len;

	len = 0;
	if (p == 0)
	{
		(*i)++;
		write(1, "(nil)", 5);
		return (5);
	}
	else if (p == 4294967295)
	{
		(*i)++;
		len = 10;
		write(1, "0xffffffff", 10);
		return (len);
	}
	else
	{
		write(1, "0x", 2);
		len = 2 + ft_print_pointer(p);
	}
	(*i)++;
	return (len);
}
