SOURCES := $(wildcard ./srcs/*.c)

OBJECTS = $(SOURCES:.c=.o)

HEADER = ./includes/

CC = cc

CFLAGS += -Wall -Wextra -Werror -I$(HEADER)

ARFLAGS = -src

NAME = libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
		ar $(ARFLAGS) $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
