NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = ./src
SRCS = push_swap.c
INClUDES = ./includes

OBJ_DIR = ./obj
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJ_DIR)/*.o $(LIBFT) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT_DIR)/libft.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR)/libft.h -I $(INClUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

