CC = cc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -rf
INClUDES = ./includes

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a


NAME_SERVER = server
SERVER_DIR = ./server_dir
SERVER_SRCS =	server.c
SERVER_OBJ_DIR = $(SERVER_DIR)/obj
SERVER_OBJS = $(patsubst %.c, $(SERVER_OBJ_DIR)/%.o, $(SERVER_SRCS))

NAME_CLIENT = client
CLIENT_DIR = ./client_dir
CLIENT_SRCS =	client.c
CLIENT_OBJ_DIR = $(CLIENT_DIR)/obj
CLIENT_OBJS = $(patsubst %.c, $(CLIENT_OBJ_DIR)/%.o, $(CLIENT_SRCS))

all: $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF): $(LIBFT)
	make -C $(FT_PRINTF_DIR)


$(NAME_SERVER): $(SERVER_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(SERVER_OBJ_DIR)/*.o $(LIBFT) $(FT_PRINTF) -o $@

$(SERVER_OBJ_DIR)/%.o: $(SERVER_DIR)/%.c $(LIBFT_DIR)/libft.h | $(SERVER_OBJ_DIR)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR)/libft.h -I $(INClUDES) -I $(FT_PRINTF_DIR)/libft.h -c $< -o $@

$(SERVER_OBJ_DIR):
	mkdir -p $@


$(NAME_CLIENT): $(CLIENT_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CLIENT_OBJ_DIR)/*.o $(LIBFT) $(FT_PRINTF) -o $@

$(CLIENT_OBJ_DIR)/%.o: $(CLIENT_DIR)/%.c $(LIBFT_DIR)/libft.h | $(CLIENT_OBJ_DIR)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR)/libft.h -I $(INClUDES) -I $(FT_PRINTF_DIR)/libft.h -c $< -o $@

$(CLIENT_OBJ_DIR):
	mkdir -p $@


clean:
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean
	$(RM) $(SERVER_OBJ_DIR)
	$(RM) $(CLIENT_OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean
	$(RM) $(NAME_SERVER)
	$(RM) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
