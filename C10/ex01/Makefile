S = ./srcs/

SRC = $S/ft_cat.c

I = ./includes/

HDR = $I/ft.h

OBJ = $(SRC:%.c=%.o)

CC = cc

CFLAGS += -Wall -Wextra -Werror -I$I

ARFLAGS = -rcs

NAME = ft_cat

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean
