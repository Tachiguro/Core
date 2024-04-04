NAME = getnextline.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
SRCS =	get_next_line.c\
		get_next_line_utils.c
OBJ_DIR = ./obj
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $(OBJS)

$(OBJ_DIR)/%.o: %.c get_next_line.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
