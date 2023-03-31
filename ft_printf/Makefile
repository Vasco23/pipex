# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 11:03:01 by vcacador          #+#    #+#              #
#    Updated: 2023/02/15 17:24:11 by vcacador         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_strlen ft_putnbr_base ft_putnbr ft_print_variable ft_putchar\
ft_checker ft_printf

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -fPIE -I.

all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)

clean:
	$(RM)	$(SRC:=.o) $(BONUS:=.o)

fclean: clean
		$(RM)	$(NAME)

re:	fclean	$(NAME)

bonus:	$(SRC:=.o)	
		ar rc $(NAME) $(SRC:=.o)
