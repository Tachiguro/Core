NAME = getnextline.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RF = -rf
SRCS =	get_next_line.c\
		get_next_line_utils.c\
OBJ = .obj
OBJS = $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(SRCS) get_next_line.h | $(OBJ)
	ar scr $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $@

$(OBJ):
	mkdir -p $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
