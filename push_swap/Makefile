NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
DEBUGFLAG = -g
RM = rm -rf
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = ./src
SRCS = 	push_swap.c\
		create_stack.c\
		find_mid.c\
		push_swap_utils.c\
		error_handling.c\
		stack_op_push_swap.c\
		stack_sort.c\
		stack_op_rotate.c\
		stack_op_comp.c

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

debug: CFLAGS += $(DEBUGFLAG)
debug: re

.PHONY: all clean fclean re

