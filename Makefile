NAME = pipex

SRC_NAME =	parse.c						\
			array_of_structs.c			\
			forks.c 					\
			child.c 					\
			parent.c 					\
			get_path.c 					\
			main.c


CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
RM = rm -f

#$(VERBOSE).SILENT:
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

FT_PRINTF = ./ft_printf/libftprintf.a
FT_PRINTF_PATH = ./ft_printf

INC = -I ./libft -I ./ft_printf -I.

SRC_PATH = ./src

OBJ_PATH = ./objects

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

all: $(NAME)

$(NAME) : $(SRC)
	make -C $(FT_PRINTF_PATH) 
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(SRC) $(INC) $(FT_PRINTF) $(LIBFT) -o $(NAME)
	clear

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	mkdir -p objects
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@
	@printf "                                                \n"
	@printf " ********************************************** \n"
	@printf " ********* Very good, Very nice!!! ************ \n"
	@printf " ********************************************** \n"
	@printf "                                                \n"

clean:
	$(RM)	$(SRC:=.o)
	make clean -s -C $(FT_PRINTF_PATH)
	make clean -s -C $(LIBFT_PATH)
	clear
	@echo "                                                "
	@echo " ********************************************** "
	@echo " **********  So Clean It Shines!  ************* "
	@echo " ********************************************** "
	@echo "                                                "

fclean: clean
		make fclean -s -C $(FT_PRINTF_PATH)
		make fclean -s -C $(LIBFT_PATH)
	$(RM)	$(NAME)

re:	fclean	$(NAME)