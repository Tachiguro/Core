CC = cc
CFLAGS = -Wall -Werror -Wextra -g #remove -g for optimization!!!!!!!!!!!!!!!!!!!!!
RM = rm -rf

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX_FLAGS = -L./minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
else
	MLX_FLAGS = -L./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit
endif

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = so_long
SRC_DIR = ./src
SRCS =	error_handling.c	\
		map_check.c			\
		map_creation.c		\
		so_long.c			\
		valid_path_in_map.c	\
		draw.c				\
		input.c				\
		so_long_utils.c

OBJ_DIR = ./obj
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJ_DIR)/*.o $(LIBFT) $(MLX_FLAGS) -o $@

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
