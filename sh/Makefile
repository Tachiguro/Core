NAME = sh
TEST_NAME = run_tests

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
OBJDIR = obj
TEST_OBJDIR = tests/obj

# Hauptquellen und Objekte ohne die main-Datei für das Testen
SRC = error_handling.c syntax.c libft.c
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

# Zusätzliche Quelldatei, die die main-Funktion enthält
MAIN_SRC = sh.c
MAIN_OBJ = $(MAIN_SRC:%.c=$(OBJDIR)/%.o)

# Testquellen und Objekte
TEST_SRC = syntax_tests.c tests.c
TEST_OBJ = $(TEST_SRC:%.c=$(TEST_OBJDIR)/%.o)
all: $(OBJDIR) $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

test: $(TEST_OBJDIR) $(TEST_OBJ) $(OBJ)
	$(CC) $(CFLAGS) -o ./tests/$(TEST_NAME) $(TEST_OBJ) $(OBJ)
	./tests/$(TEST_NAME)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_OBJDIR)/%.o: tests/%.c | $(TEST_OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) $(TEST_OBJDIR):
	mkdir -p $@

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(MAIN_OBJ)
	rm -rf $(OBJDIR) $(TEST_OBJDIR)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re test
