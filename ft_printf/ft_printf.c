/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:13:39 by vcacador          #+#    #+#             */
/*   Updated: 2022/11/08 11:11:59 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	find_char(const char *str);
static	char	*ft_next(char *str);

int	ft_printf(const char *str, ...)
{
	int		lenprint;
	va_list	args;
	char	c;

	lenprint = 0;
	va_start(args, str);
	while (*str)
	{
		c = find_char(str);
		if (*str == '%')
		{
			lenprint += print_variable((char *)str, &args, lenprint, c);
			str = ft_next((char *)str);
		}
		else
		{
			ft_putchar(*str);
			lenprint += 1;
		}
		str++;
	}
	va_end(args);
	return (lenprint);
}

static char	find_char(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] != '%') && str[i])
		i++;
	if (!str[i])
		return ('\0');
	while (str[++i])
	{
		if ((ft_checker("cdisxXpu", str[i]) == 1) || str[i] == '%')
			return (str[i]);
	}
	return ('\0');
}

static	char	*ft_next(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '%')
		i++;
	i++;
	while (str[i])
	{
		if (ft_checker("cdisxXpu", str[i]) == 1 || str[i] == '%')
			break ;
		i++;
	}
	while (--i >= 0)
		str++;
	return (str);
}
