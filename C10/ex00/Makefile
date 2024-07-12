S = ./srcs/

SRC = $S/ft_display_file.c

OBJ = $(SRC:%.c=%.o)

CC = cc

CFLAGS += -Wall -Wextra -Werror

ARFLAGS = -rcs

NAME = ft_display_file

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re
