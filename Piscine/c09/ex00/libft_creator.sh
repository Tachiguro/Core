# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 22:59:24 by jherzog           #+#    #+#              #
#    Updated: 2023/02/16 23:07:36 by jherzog          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh
ar rc libft.a ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
rm -f *.o