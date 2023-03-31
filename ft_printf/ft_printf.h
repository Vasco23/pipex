/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:15:16 by vcacador          #+#    #+#             */
/*   Updated: 2022/11/08 11:27:28 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include  <stdio.h>
# include  <stdlib.h>
# include  <string.h>
# include  <unistd.h>
# include  <stdarg.h>

int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *str);
int		ft_putnbr_base(unsigned long long nb, char *str,
			int lenprint, int checker);
int		ft_putnbr(char *str, int nb, int lenprint, int checker);
int		print_variable(char *str, va_list *args, int lenprint, char c);
void	ft_putchar(char c);
int		ft_checker(char *convert, char c);

#endif
