/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_low.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:00:23 by ikhanenk          #+#    #+#             */
/*   Updated: 2024/09/09 13:52:07 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_positive(unsigned int p)
{
	char	*base;
	char	ch;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (p >= 16)
	{
		len += print_positive(p / 16);
		len += print_positive(p % 16);
	}
	else if (p < 16)
	{
		ch = base[p];
		len += 1;
		write(1, &ch, 1);
	}
	return (len);
}

int	print_hex_low(unsigned int p)
{
	int	len;

	len = 0;
	if (p == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		len = print_positive(p);
	return (len);
}
