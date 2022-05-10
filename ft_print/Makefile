# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 13:33:55 by jherzog           #+#    #+#              #
#    Updated: 2022/05/10 19:31:44 by jherzog          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SOURCE	=	ft_printf.c		\
			ft_print_func.c	\
			ft_ultoh.c		\

OBJS = $(SOURCE:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

CC 		=	cc

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SOURCE)
	ar -r $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
