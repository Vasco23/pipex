/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:10:13 by vcacador          #+#    #+#             */
/*   Updated: 2022/11/08 11:28:11 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_string(char *str, char *str2);
static int	print_char(char c);

int	print_variable(char *str, va_list *args, int lenprint, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(str, (int)va_arg(*args, int), 0, 0));
	else if (c == 'p')
		return (ft_putnbr_base((unsigned long)va_arg(*args,
					unsigned long), str, 0, 0));
	else if (c == 'u')
		return (ft_putnbr_base((unsigned)va_arg(*args, unsigned), str, 0, 0));
	else if (c == 'x')
		return (ft_putnbr_base((unsigned)va_arg(*args, unsigned), str, 0, 0));
	else if (c == 'X')
		return (ft_putnbr_base((unsigned)va_arg(*args, unsigned), str, 0, 0));
	else if (c == 's')
		return (print_string(va_arg(*args, char *), str));
	else if (c == 'c')
		return (print_char(va_arg(*args, int)));
	else if (c == '%')
		return (print_char('%'));
	return (lenprint);
}

static int	print_string(char *str, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str2[i] != '%' && str2[i])
		i++;
	while (str2[++i] != 's')
	{
		if (str2[i] == ' ' && str2[i + 1] == '1')
		{
			ft_putchar(' ');
			j = 1;
		}
	}
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (i + j);
}

static int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}
