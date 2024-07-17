S = ./srcs/

SRC = $S/main.c $S/helper_functions.c $S/init.c $S/print_rows.c

I = ./includes/

HDR = $I/ft_hexdump.h

OBJ = $(SRC:%.c=%.o)

CC = cc

CFLAGS += -Wall -Wextra -Werror -I$I

NAME = ft_hexdump

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
