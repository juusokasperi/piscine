SOURCES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

PATH_SOURCES = $(addprefix ./srcs/, $(SOURCES))

OBJECTS = $(PATH_SOURCES:.c=.o)

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
