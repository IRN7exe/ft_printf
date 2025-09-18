/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:49:44 by ikhanenk          #+#    #+#             */
/*   Updated: 2024/09/11 15:22:33 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	this_is_ph(char c)
{
	if (c == 'c' || c == 's' || \
		c == 'i' || c == 'u' || c == 'p' || \
		c == 'x' || c == 'X' || c == 'd')
		return (1);
	return (0);
}

static int	just_print(char *str, int i)
{
	while (str[i])
	{
		while (str[i] != '%' && str[i])
			write(1, str + i++, 1);
		while (str[i] == '%' && str[i + 1] == '%' && str[i])
		{
			write(1, "%", 1);
			i += 2;
		}
		if (str[i] == '%' && this_is_ph(str[i + 1]))
			return (++i);
		else if (str[i])
			write(1, str + i++, 1);
	}
	return (i);
}

static int	ft_strlen(char *s, int i)
{
	int	len;

	len = 0;
	while (s[i])
	{
		if (s[i] != '%')
			len += 1;
		if (s[i] == '%' && (this_is_ph(s[i + 1]) || s[i + 1] == '%'))
			i++;
		if (s[i] == '%')
			len += 1;
		i++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	va_start(ap, str);
	len = ft_strlen((char *)str, i);
	while (str[i])
	{
		i = just_print((char *)str, i);
		if (str[i] == 'c')
			len = len + print_char(va_arg(ap, int), &i);
		else if (str[i] == 's')
			len = len + print_str(va_arg(ap, char *), &i);
		else if (str[i] == 'd' || str[i] == 'i')
			len = len + print_num(va_arg(ap, int), str[i], &i);
		else if (str[i] == 'x' || str[i] == 'X')
			len = len + print_num(va_arg(ap, int), str[i], &i);
		else if (str[i] == 'u')
			len = len + print_num(va_arg(ap, unsigned int), str[i], &i);
		else if (str[i] == 'p')
			len = len + print_pointer(va_arg(ap, unsigned long), &i);
	}
	va_end(ap);
	return (len);
}
