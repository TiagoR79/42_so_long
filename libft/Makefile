NAME = libft.a
SRC = ft_atoi ft_putchar_fd ft_putnbr_fd ft_putstr_fd ft_strdup ft_strlen
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.


all:$(NAME)

$(NAME): $(SRC:=.o)
					ar rc $(NAME) $(SRC:=.o)

clean:
	$(RM)	$(SRC:=.o) $(BONUS:=.o)
fclean: clean
		$(RM)	$(NAME)
re:	fclean	$(NAME)
bonus:	$(SRC:=.o)	$(BONUS:=.o)
		ar rc $(NAME) $(SRC:=.o)	$(BONUS:=.o)
