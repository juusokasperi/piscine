S = ft_atoi.c ft_putnbr.c main.c

SRC_PATH = $(addprefix ./srcs/, $S)

O = $(SRC_PATH:.c=.o)

H = doop.h

I = ./includes/

HDR_PATH = $(addprefix $I, $H)

CC = cc

CFLAGS += -Wall -Wextra -Werror -I$I

NAME = doop

all: $(NAME)

%.o: %.c $(HDR_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(O)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
