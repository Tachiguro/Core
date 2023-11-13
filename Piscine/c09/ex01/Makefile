# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 23:11:50 by jherzog           #+#    #+#              #
#    Updated: 2023/02/16 23:27:57 by jherzog          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE = ./srcs/ft_putchar.c\
		./srcs/ft_swap.c\
		./srcs/ft_putstr.c\
		./srcs/ft_strlen.c\
		./srcs/ft_strcmp.c

OBJECTS = $(SOURCE:.c=.o)

HEADER = ./includes/ft.h

FLAGS = -Wall -Wextra -Werror

CC = cc

all:$(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

clean:
	rm $(OBJECTS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all
