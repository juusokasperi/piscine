SOURCES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

PATH_SOURCES = $(addprefix ./srcs/, $(SOURCES))

OBJECTS = $(PATH_SOURCES:.c=.o)

HEADERS = ft.h

INCLUDES = ./includes/

PATH_HEADER = $(addprefix $(INCLUDES), $(HEADERS))

CC = cc

CFLAGS += -Wall -Wextra -Werror -I$(INCLUDES)

ARFLAGS = -rcs

NAME = libft.a

all: $(NAME)

%.o: %.c $(PATH_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
		ar $(ARFLAGS) $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
