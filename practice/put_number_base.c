/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_number_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 07:03:24 by jherzog           #+#    #+#             */
/*   Updated: 2023/12/20 17:19:58 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	put_number_base(int nb, char *base)
{
	int	size;

	size = strlen(base);
	if (nb < 0)
		return ;
	if (nb >= size)
	{
		put_number_base(nb / size, base);
		nb %= size;
	}
	write(1, base + nb, 1);
}

int	main(int argc, char **argv)
{
	int		nb;
	char	*base;

	if (argc != 3)
	{
		printf("How to use?\n%s <number> <base>\n", argv[0]);
		printf("\nexample:\n%s 42 01\n", argv[0]);
		printf("nb:42\n");
		printf(" ");
		return (1);
	}
	nb = atoi(argv[1]);
	if (nb < 0)
		printf("No negative number!\n");
	base = argv[2];
	printf("nb:%d\n", nb);
	put_number_base(nb, base);
	printf("\n");
	printf("\n\n%d\n", 1 + 1);
	char x = 65;
	char y = 66;
	printf("x=%c , y=%c %d\n", x, y, x + y);

	return (0);
}

