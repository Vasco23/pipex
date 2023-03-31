/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:16:05 by vcacador          #+#    #+#             */
/*   Updated: 2022/11/08 11:28:04 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		find_char2(char *str);
static char		*ft_base_type(char *str);
static int		ft_bonus_print(char *str, unsigned long long nb);
static int		ft_get_lenprint(char *str, unsigned long long nb);

int	ft_putnbr_base(unsigned long long nb, char *str, int lenprint, int checker)
{
	char	*base;

	if (checker == 0)
	{
		lenprint += ft_bonus_print(str, nb);
		if (nb == 0 && find_char2(str) == 'p')
			return (lenprint);
		lenprint += ft_get_lenprint(str, nb);
	}
	base = ft_base_type(str);
	if (nb >= strlen(base))
	{
		lenprint += 1;
		lenprint = ft_putnbr_base(nb / ft_strlen(base),
				str, lenprint, checker += 1);
		ft_putchar(base[nb % ft_strlen(base)]);
	}
	if (nb < strlen(base))
	{
		ft_putchar(base[nb % ft_strlen(base)]);
		lenprint += 1;
	}
	return (lenprint);
}

static char	find_char2(char *str)
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

static char	*ft_base_type(char *str)
{
	char	c;

	c = find_char2(str);
	if (c == 'u')
		return ("0123456789");
	else if (c == 'p' || c == 'x')
		return ("0123456789abcdef");
	else if (c == 'X')
		return ("0123456789ABCDEF");
	return (NULL);
}

static int	ft_bonus_print(char *str, unsigned long long nb)
{
	int	i;

	i = 0;
	while (str[i] != '%')
		i++;
	while (ft_checker("pxXu", str[i]) != 1)
		i++;
	if (str[i] == 'u')
		return (0);
	if ((nb == 0) && ((str[i - 1] == '#' && str[i] == 'x')
			|| (str[i - 1] == '#' && str[i] == 'X')))
		return (0);
	if ((str[i] == 'p') && (nb == 0))
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else if ((str[i] == 'p') || (str[i - 1] == '#' && str[i] == 'x'))
		write(1, "0x", 2);
	else if (str[i - 1] == '#' && str[i] == 'X')
		write(1, "0X", 2);
	return (0);
}

static int	ft_get_lenprint(char *str, unsigned long long nb)
{
	int	i;

	i = 0;
	while (str[i] != '%')
		i++;
	while (ft_checker("pxuX", str[i]) != 1)
		i++;
	if (((str[i - 1] == '#' && str[i] == 'x')
			|| (str[i - 1] == '#' && str[i] == 'X')) && (nb == 0))
		return (0);
	else if (((str[i - 1] == '#' && str[i] == 'x')
			|| (str[i - 1] == '#' && str[i] == 'X')) || (str[i] == 'p'))
		return (2);
	else if (str[i] == 'u')
		return (0);
	return (0);
}
