/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:27:35 by ikhanenk          #+#    #+#             */
/*   Updated: 2024/09/08 18:17:41 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num(long long nb, char c, int *i)
{
	int	len;

	len = 0;
	if ((c == 'i' || c == 'd' || c == 'u') && nb >= 0)
		len = ft_print_int(nb);
	else if ((c == 'i' || c == 'd' || c == 'u') && nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2", 2);
			len = 2 + ft_print_int(147483648);
		}
		else if (nb != -2147483648)
		{
			write(1, "-", 1);
			len = 1 + ft_print_int((-nb));
		}
	}
	else if (c == 'x' || c == 'X')
		len = print_hex(nb, c);
	(*i)++;
	return (len);
}
