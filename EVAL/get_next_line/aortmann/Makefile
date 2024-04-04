NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c

OPTIONS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	ar rcs $(NAME) $^

%.o: %.c
	cc $(OPTIONS) -c $< -o $@

clean:
	/bin/rm -f $(SRC:.c=.o)
	/bin/rm -f $(NAME)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all