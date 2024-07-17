S = ./srcs/

SRC = $S/ft_display_file.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS += -Wall -Wextra -Werror

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

re: fclean all

.PHONY: all clean fclean re
