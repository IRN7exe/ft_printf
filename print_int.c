/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:25:50 by ikhanenk          #+#    #+#             */
/*   Updated: 2024/09/08 18:17:33 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_int(long long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / 10;
		len += 1;
	}
	return (len);
}

int	ft_print_int(long long nb)
{
	char	p;
	int		len;

	len = len_int(nb);
	if (nb > 9)
	{
		ft_print_int(nb / 10);
		ft_print_int(nb % 10);
	}
	else
	{
		p = '0' + nb;
		write(1, &p, 1);
	}
	return (len);
}
