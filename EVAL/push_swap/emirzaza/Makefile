# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emirzaza <emirzaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 14:00:55 by emirzaza          #+#    #+#              #
#    Updated: 2023/07/10 18:51:02 by emirzaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

SRCS= push_instructions.c rotate_instructions.c swap_instructions.c validator.c \
	  rev_rotate_instructions.c sort.c utils.c main.c stack.c radix_sort.c basic_sort.c \

OBJS=$(SRCS:.c=.o)

CC=gcc
CFLAGS= -Wall -Wextra -Werror

RM= rm -rf

all:$(NAME)

${NAME}: $(OBJS)
		${MAKE} -C ./libft
		${MAKE} bonus -C ./libft
		${CC} $(CFLAGS) $(OBJS) ./libft/libft.a -o ${NAME}

clean: 
		@${MAKE} -C ./libft fclean
		@${RM} $(OBJS)

fclean:	clean
		@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
