# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 18:17:04 by jherzog           #+#    #+#              #
#    Updated: 2023/11/12 18:44:27 by jherzog          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM = rm -rf
SRCS = 	srcs/ft_putchar.c	\
		srcs/ft_putstr.c	\
		srcs/ft_strcmp.c	\
		srcs/ft_strlen.c	\
		srcs/ft_swap.c

OBJS = $(patsubst %.c,%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I includes -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
