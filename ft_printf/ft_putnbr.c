/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:21:58 by vcacador          #+#    #+#             */
/*   Updated: 2022/11/08 11:27:04 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_max_negative_nbr(int nb);
static int	if_negative(int nb);
static int	ft_bonus(char *str, int lenprint);

int	ft_putnbr(char *str, int nb, int lenprint, int checker)
{
	if (nb == -2147483648)
		return (ft_max_negative_nbr(nb));
	if (nb >= 0 && checker == 0)
		lenprint += ft_bonus(str, 0);
	if (nb < 0)
	{
		nb = if_negative(nb);
		lenprint += 1;
	}
	if (nb >= 10)
	{
		lenprint += 1;
		lenprint = ft_putnbr(str, nb / 10, lenprint, checker += 1);
		ft_putchar("0123456789"[nb % 10]);
	}
	else if (nb < 10)
	{
		ft_putchar("0123456789"[nb % 10]);
		lenprint += 1;
	}
	return (lenprint);
}

static int	ft_max_negative_nbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	return (11);
}

static int	if_negative(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	return (nb);
}

static int	ft_bonus(char *str, int lenprint)
{
	int	i;

	i = 0;
	while (str[i] != '%')
		i++;
	while (ft_checker("cdisxXpu", str[i++]) == 0)
	{
		if (str[i] == '+' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		{
			write(1, "+", 1);
			lenprint += 1;
		}
		else if (str[i] == ' ' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		{
			write(1, " ", 1);
			lenprint += 1;
		}
	}
	return (lenprint);
}
