SOURCES = ft_display_file.c

PATH_SOURCES = $(addprefix, ./srcs/$(SOURCES))

CC = cc

CFLAGS += -Wall -Wextra -Werror

ARFLAGS = -rcs

NAME = ft_display_file

$(NAME):
	$(CC) $(CFLAGS) $(PATH_SOURCES) -o $(NAME)

all: $(NAME)

.PHONY: all
