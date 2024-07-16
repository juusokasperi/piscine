SOURCES = ft_atoi.c ft_tail.c main.c print_handlers.c print_handlers_2.c init.c

PATH_SOURCES = $(addprefix ./srcs/, $(SOURCES))

OBJECTS = $(PATH_SOURCES:.c=.o)

HEADERS = ft_tail.h

INCLUDES = ./includes/

PATH_HEADER = $(addprefix $(INCLUDES), $(HEADERS))

CC = cc

CFLAGS += -Wall -Wextra -Werror -I$(INCLUDES)

NAME = ft_tail

all: $(NAME)

%.o: %.c $(PATH_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
