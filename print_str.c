/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:56:54 by ikhanenk          #+#    #+#             */
/*   Updated: 2024/09/08 19:32:28 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str, int *i)
{
	int	n;
	int	len;

	n = 0;
	len = 0;
	if (!str)
	{
		(*i)++;
		write(1, "(null)", 6);
		return (6);
	}
	if (str[n] == '\0')
	{
		(*i)++;
		return (0);
	}
	while (str[n])
	{
		write(1, &str[n], 1);
		len += 1;
		n++;
	}
	(*i)++;
	return (len);
}
