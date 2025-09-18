/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:54:32 by ikhanenk          #+#    #+#             */
/*   Updated: 2024/09/09 13:42:37 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <stdarg.h>
#include <malloc.h>
#include <limits.h>

int		ft_printf(const char *str, ...);
int		print_char(char ch, int *i);
int		print_str(char *str, int *i);

int		print_num(long long nb, char c, int *i);
int		ft_print_int(long long nb);

int		print_pointer(unsigned long p, int *i);

int		print_hex(unsigned int p, char c);
int		print_hex_up(unsigned int p);
int		print_hex_low(unsigned int p);