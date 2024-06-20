/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:18:11 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/20 01:02:40 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_stack *stack_a)
{
	int	temp;

	if (stack_a->top < 1)
		return ;
	temp = stack_a->array[stack_a->top];
	stack_a->array[stack_a->top] = stack_a->array[stack_a->top - 1];
	stack_a->array[stack_a->top - 1] = temp;
	printf("sa\n");
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_stack *stack_b)
{
	int	temp;

	if (stack_b->top < 1)
		return ;
	temp = stack_b->array[stack_b->top];
	stack_b->array[stack_b->top] = stack_b->array[stack_b->top - 1];
	stack_b->array[stack_b->top - 1] = temp;
	printf("sb\n");
}

// pa push a: Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top < 0)
		return ;
	stack_a->array[++(stack_a->top)] = stack_b->array[(stack_b->top)--];
	printf("pa\n");
}

// pb push b: Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top < 0)
		return ;
	stack_b->array[++(stack_b->top)] = stack_a->array[(stack_a->top)--];
	if (stack_b->max < stack_b->array[stack_b->top])
		stack_b->max = stack_b->array[stack_b->top];
	if (stack_b->min > stack_b->array[stack_b->top])
		stack_b->min = stack_b->array[stack_b->top];
	write(1, "pb\n", 3);
}
