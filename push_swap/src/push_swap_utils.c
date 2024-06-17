/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:35:38 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/17 19:17:36 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	a;
	int	b;

	a = stack_a->top;
	b = stack_b->top;
	write(1, "---------\n", 10);
	while (a >= 0)
	{
		ft_putnbr_fd(stack_a->array[a], 1);
		write(1, "\t", 1);
		if (b >= 0 && b == a)
		{
			ft_putnbr_fd(stack_b->array[b], 1);
			b--;
		}
		a--;
		write(1, "\n", 1);
	}
	write(1, "-\t-\n", 4);
	write(1, "a\tb\n", 4);
	write(1, "---------\n", 10);
}


bool	stack_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i > 0)
	{
		if (stack->array[i] > stack->array[i - 1])
			return (false);
		i--;
	}
	return (true);
}

