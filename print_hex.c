/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:08:31 by ikhanenk          #+#    #+#             */
/*   Updated: 2024/09/09 13:46:46 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int p, char c)
{
	int	len;

	len = 0;
	if (c == 'X')
		len = print_hex_up(p);
	else if (c == 'x')
		len = print_hex_low(p);
	return (len);
}
