# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 13:33:55 by jherzog           #+#    #+#              #
#    Updated: 2022/05/13 00:28:36 by jherzog          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SOURCE	=	ft_itoa.c		\
			ft_memcpy.c		\
			ft_print_func.c	\
			ft_printf.c		\
			ft_strdup.c		\
			ft_strlen.c		\
			ft_toupper.c	\
			ft_ultoh.c		\
			main.c			\


CFLAGS	=	-g -Wall -Wextra -Werror

CC		=	gcc

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCE) -o test

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
