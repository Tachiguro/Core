/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:47:12 by jherzog           #+#    #+#             */
/*   Updated: 2024/05/06 20:17:26 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	*create_stack(char *numbers, char *argv[])
// {
// 	int len;

// 	len = ft_strlen(numbers);
// }

int	check_correct_input(int argc, char *argv[])
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (++len < argc)
	{
		i += ft_strlen(argv[len]);
	}
	return (i);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	// int	*stack_a;
	// int	*stack_b;
	int i;

	i = 0;
	if (argc == 1)
		exit(1);
	else
	{
		i = check_correct_input(argc, argv);
		printf("i = %i\n", i);
	}
	return (0);
}
