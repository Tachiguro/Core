# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jherzog <jherzog@student.42.frf>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 18:29:58 by jherzog           #+#    #+#              #
#    Updated: 2023/07/13 19:57:15 by jherzog          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM = rm -rf
SRCS	=		ft_atoi.c			\
				ft_bzero.c			\
				ft_calloc.c			\
				ft_isalnum.c		\
				ft_isalpha.c		\
				ft_isascii.c		\
				ft_isdigit.c		\
				ft_isprint.c		\
				ft_itoa.c			\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_memcpy.c			\
				ft_memmove.c		\
				ft_memset.c			\
				ft_putchar_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_putstr_fd.c		\
				ft_split.c			\
				ft_strchr.c			\
				ft_strdup.c			\
				ft_striteri.c		\
				ft_strjoin.c		\
				ft_strlcat.c		\
				ft_strlcpy.c		\
				ft_strlen.c			\
				ft_strmapi.c		\
				ft_strncmp.c		\
				ft_strnstr.c		\
				ft_strrchr.c		\
				ft_strtrim.c		\
				ft_substr.c			\
				ft_tolower.c		\
				ft_toupper.c

SRCS_BONUS =	ft_lstadd_back.c	\
				ft_lstadd_front.c	\
				ft_lstlast.c		\
				ft_lstnew.c			\
				ft_lstsize.c		\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c

OBJ_DIR = obj
OBJS =			$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
OBJS_BONUS =	$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS_BONUS))

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS) $(OBJS_BONUS)

bonus: $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS_BONUS)

$(OBJ_DIR)/%.o: %.c libft.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean bonus

	@rm a.out
	@make fclean

	@rm a.out
	@make fclean

	@rm a.out
	@make fclean

	@rm a.out
	@make fclean

	@rm a.out
	@make fclean

	@rm a.out
	@make fclean

	@rm a.out
	@make fclean

	@rm a.out
	@make fclean

	@rm a.out
	@make fclean
