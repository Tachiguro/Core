CC = cc
CFLAGS = -Wall -Werror -Wextra

# Tests
TEST_LIBFT =		t_libft
LIBFT_DIR =			./libft
LIBFT =				$(LIBFT_DIR)/libft.a

TEST_FT_PRINTF =	t_ftprintf
FTPRINTF_DIR =		./ft_printf
FTPRINTF =			$(FTPRINTF_DIR)/libftprintf.a

TESTS =				$(TEST_FT_PRINTF)\
					$(TEST_LIBFT)

TESTS_DIR =			$(LIBFT_DIR)\
					$(FTPRINTF_DIR)

all: $(TESTS)

$(TEST_FT_PRINTF): $(FTPRINTF) test_ft_printf.c
	$(CC) $(CFLAGS) -o $@ test_ft_printf.c $(FTPRINTF)
$(FTPRINTF):
	make -C $(FTPRINTF_DIR)

$(TEST_LIBFT): $(LIBFT) test_libft.c
	$(CC) $(CFLAGS) -o $@ test_libft.c $(LIBFT)
$(LIBFT):
	make -C $(LIBFT_DIR)

fclean: clean
	for dir in $(TESTS_DIR); do\
		make -C $$dir fclean; \
	done
	$(RM) $(TESTS)

clean:
	for dir in $(TESTS_DIR); do \
		make -C $$dir clean; \
	done

re: fclean all

.PHONY: all re fclean clean
