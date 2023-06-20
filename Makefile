NAME = pipex

SRC_NAME =	parse.c						\
			array_of_structs.c			\
			forks.c 					\
			child.c 					\
			get_path.c 					\
			here_doc.c					\
			get_next_line.c				\
			get_next_line_utils.c		\
			main.c


CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
RM = rm -f

#$(VERBOSE).SILENT:
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

FT_PRINTF = ./ft_printf/libftprintf.a
FT_PRINTF_PATH = ./ft_printf

INC = -I ./inc	-I ./libft	-I ./ft_printf

SRC_PATH = ./src

OBJ_PATH = ./objects

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

all: $(NAME)

$(NAME) : $(OBJS)
	make -C $(FT_PRINTF_PATH) 
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(SRC) $(INC) $(FT_PRINTF) $(LIBFT) -o $(NAME)
	clear
	@printf "                                                \n"
	@printf " ********************************************** \n"
	@printf " ********* Very good, Very nice!!! ************ \n"
	@printf " ********************************************** \n"
	@printf "                                                \n"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	mkdir -p objects
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	$(RM)	$(SRC:=.o)
	make clean -C $(FT_PRINTF_PATH)
	make clean -C $(LIBFT_PATH)
	clear
	@echo "                                                "
	@echo " ********************************************** "
	@echo " **********  So Clean It Shines!  ************* "
	@echo " ********************************************** "
	@echo "                                                "

fclean: clean
		make fclean -C $(FT_PRINTF_PATH)
		make fclean -C $(LIBFT_PATH)
	$(RM)	$(NAME)

re:	fclean	$(NAME)

.PHONY: all clean fclean re