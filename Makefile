NAME = test
FTPRINTFDIR = ./ft_printf
FTPRINTF = $(FTPRINTFDIR)/libftprintf.a

all: $(NAME)

$(NAME): $(FTPRINTF) test.c
	gcc -o $@ test.c $(FTPRINTF)

$(FTPRINTF):
	make -C $(FTPRINTFDIR)

fclean: clean
	make -C $(FTPRINTFDIR) fclean
	$(RM)
	$(RM) ./test

clean:
	make -C $(FTPRINTFDIR) clean

re: fclean all

.PHONY: all re
