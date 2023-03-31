/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:09:33 by vcacador          #+#    #+#             */
/*   Updated: 2022/11/03 14:10:05 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(char *convert, char c)
{
	int	i;

	i = -1;
	while (convert[++i])
	{
		if (c == convert[i])
			return (1);
	}
	return (0);
}
