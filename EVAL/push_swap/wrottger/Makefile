NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SOURCES = 	main.c stack_utils.c stack_operations.c \
			utils.c sort.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJECTS) -L./libft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all
