NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = ./src
SRCS =	ft_printf.c		\
		ft_print_char.c	\
		ft_print_hex.c	\
		ft_print_int.c	\
		ft_print_ptr.c	\
		ft_print_str.c	\
		ft_print_uint.c

OBJ_DIR = ./obj
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar -rcs $@ $(OBJS)
	ar -s $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ft_printf.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I ft_printf.h -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

