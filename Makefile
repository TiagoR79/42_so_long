	# Library Name #
NAME	= so_long
	# libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft


	# Mandatory Variables #
SRC		=	./srcs/main.c \
			./srcs/*/*.c

INC		=	./includes/*.h -I$(LIBFT_DIR)

	# Compiling Variables #
CC			=	gcc
CFLAG		=	#-Wall -Wextra -Werror
FLAGS_LINUX	=	-lbsd -lmlx -lXext -lX11
FLAGS_MAC	=	-lmlx -framework OpenGL -framework AppKit -lm
RM			=	rm -f

all: $(NAME)

compile_libraries:
	$(MAKE) -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)/libft.a .

$(NAME): all

#$(NAME): compile_libraries
#	@ $(CC) $(CFLAG) $(SRC) $(INC) $(FLAGS_MAC) -o $(NAME)
#	@printf "so_long ready.\n"
$(NAME): compile_libraries
	@ $(CC) $(CFLAG) $(SRC) $(INC) $(FLAGS_LINUX) -o $(NAME)
	@printf "so_long ready.\n"

clean:
	rm -f $(NAME)

fclean:	clean
	make fclean -C ./libft
	rm -f libft.a
	@printf "all cleaned.\n"

re: fclean all

mandatory:	$(NAME)
bonus:		mandatory

m : mandatory
b : bonus

.PHONY: all clean fclean re mandatory m bonus b
