NAME	=	libftprintf.a

SOURCE	=	ft_itoh.c		\
			ft_print_func.c	\
			ft_printf.c		\
			ft_ultoh.c		\

OBJS = $(SOURCE:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

CC		=	cc

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(CFLAGS) -c $(SOURCE)
	ar -r $(NAME) $(OBJS) libft/*.o
clean:
	rm -f *.o
	cd libft && rm -f *.o

fclean: clean
	rm -f $(NAME)
	cd libft && rm -f *.a

re: fclean all
