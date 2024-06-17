/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:35:38 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/17 22:29:32 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	a;
	int	b;
	int	max;

	a = stack_a->top;
	b = stack_b->top;
	if (a > b)
		max = a;
	else
		max = b;
	write(1, "---------\n", 10);
	while (max >= 0)
	{
		if (a >= 0 && a == max)
			ft_putnbr_fd(stack_a->array[a--], 1);
		write(1, "\t", 1);
		if (b >= 0 && b == max)
			ft_putnbr_fd(stack_b->array[b--], 1);
		max--;
		write(1, "\n", 1);
	}
	write(1, "---------\n", 10);
	write(1, "a\tb\n", 4);
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
