NAME = test_ft_printf
FTPRINTF_DIR = ./ft_printf
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(FTPRINTF) test_ft_printf.c
	gcc -o $@ test.c $(FTPRINTF)

$(FTPRINTF):
	make -C $(FTPRINTF_DIR)

fclean: clean
	make -C $(FTPRINTF_DIR) fclean
	$(RM)
	$(RM) ./test

clean:
	make -C $(FTPRINTF_DIR) clean

re: fclean all

.PHONY: all re
