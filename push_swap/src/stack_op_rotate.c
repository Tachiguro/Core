/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:15:16 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/18 16:15:12 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_stack *stack_a)
{
	int	temp;
	int	i;

	if (stack_a->top < 1)
		return ;
	temp = stack_a->array[stack_a->top];
	i = stack_a->top;
	while (i > 0)
	{
		stack_a->array[i] = stack_a->array[i - 1];
		i--;
	}
	stack_a->array[0] = temp;
	write(1, "ra\n", 3);
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_stack *stack_b)
{
	int	temp;
	int	i;

	if (stack_b->top < 1)
		return ;
	temp = stack_b->array[stack_b->top];
	i = stack_b->top;
	while (i > 0)
	{
		stack_b->array[i] = stack_b->array[i - 1];
		i--;
	}
	stack_b->array[0] = temp;
	write(1, "rb\n", 3);
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_stack *stack_a)
{
	int	temp;
	int	i;

	if (stack_a->top < 1)
		return ;
	temp = stack_a->array[0];
	i = 0;
	while (i < stack_a->top)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
	stack_a->array[stack_a->top] = temp;
	write(1, "rra\n", 4);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_stack *stack_b)
{
	int	temp;
	int	i;

	if (stack_b->top < 1)
		return ;
	temp = stack_b->array[0];
	i = 0;
	while (i < stack_b->top)
	{
		stack_b->array[i] = stack_b->array[i + 1];
		i++;
	}
	stack_b->array[stack_b->top] = temp;
	write(1, "rrb\n", 4);
}
