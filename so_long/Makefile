CC = cc
CFLAGS = -Wall -Werror -Wextra -g #remove -g for optimization!!!!!!!!!!!!!!!!!!!!!
RM = rm -rf

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = so_long
SRC_DIR = ./src
SRCS =	so_long.c		\
		map_check.c		\
		path_check.c

OBJ_DIR = ./obj
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJ_DIR)/*.o $(LIBFT) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT_DIR)/includes/libft.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR)/includes/libft.h -I ./includes -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
