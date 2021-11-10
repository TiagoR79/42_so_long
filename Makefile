	# Library Name #
NAME	= so_long
	# libft Variables #
#LIBFT		=	./libft/libft.a
#LIBFT_DIR	=	./libft


	# Mandatory Variables #
SRC		=	test.c
INC		=

	# Compiling Variables #
CC			=	gcc
CFLAG		=	#-Wall -Wextra -Werror
FLAGS_LINUX	=	-lbsd -lmlx -lXext -lX11
FLAGS_MAC	=	-lmlx -framework OpenGL -framework AppKit -lm
RM			=	rm -f

all: $(NAME)

$(NAME): all

#$(NAME):
#	@ $(CC) $(CFLAG) $(SRC) $(FLAGS_MAC) -o $(NAME)
#	@printf "so_long ready.\n"
$(NAME):
	@ $(CC) $(CFLAG) $(SRC) $(FLAGS_LINUX) -o $(NAME)
	@printf "so_long ready.\n"
#$(LIBFT):
#	@ $(MAKE) -C ./libft

clean:
						rm -f $(NAME)

fclean:
						rm -rf $(NAME)

re: fclean all

mandatory:	$(NAME)
bonus:		mandatory

m : mandatory
b : bonus

.PHONY: all clean fclean re mandatory m bonus b
