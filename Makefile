# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tribeiro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 11:25:50 by tribeiro          #+#    #+#              #
#    Updated: 2021/12/15 10:56:38 by tribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#MAKEFLAGS	+=	--quiet

	# Library Name #
NAME	= so_long

	# libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

	# Mandatory Variables #
SRC		=	./srcs/*.c \
			./srcs/*/*.c

INC		=	./includes/*.h -I$(LIBFT_DIR)

	# Compiling Variables #
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror -g #-fsanitize=address

FLAGS_LINUX	=	-lbsd -lmlx -lXext -lX11
FLAGS_MAC	=	-lmlx -framework OpenGL -framework AppKit -lm
RM			=	rm -f

all: $(NAME)

compile_libraries:
	@ $(MAKE) -C $(LIBFT_DIR)
	@ mv $(LIBFT_DIR)/libft.a .

$(NAME): all

$(NAME): compile_libraries #$(LIBFT) $(SRC)
	@$(CC) $(CFLAG) $(FLAGS_MAC) $(SRC) -o $(NAME)
#	@ $(CC) $(CFLAG) $(SRC) $(FLAGS_LINUX) -o $(NAME)
	@printf "so_long ready.\n"
	@printf "\n=========================\n\n"

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
