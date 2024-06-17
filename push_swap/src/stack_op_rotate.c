/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:15:16 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/17 13:54:17 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// rrr : rra and rrb at the same time.
// rr : ra and rb at the same time.

void	r_a(t_stack *stack_a)
{
	int	temp;

	temp = 0;
	temp = stack_a->array[stack_a->top];
	while (stack_a->top < stack_a->len - 1)
	{
		stack_a->array[stack_a->top] = stack_a->array[stack_a->top + 1];
		stack_a->top++;
	}
	stack_a->array[stack_a->top] = temp;
	printf("ra\n");
}

void	r_b(t_stack *stack_b)
{
	int	temp;

	temp = 0;
	temp = stack_b->array[stack_b->top];
	while (stack_b->top < stack_b->len - 1)
	{
		stack_b->array[stack_b->top] = stack_b->array[stack_b->top + 1];
		stack_b->top++;
	}
	stack_b->array[stack_b->top] = temp;
	printf("rb\n");
}

void	rra(t_stack *stack_a)
{
	int	temp;

	temp = 0;
	temp = stack_a->array[stack_a->len - 1];
	while (stack_a->top < stack_a->len - 1)
	{
		stack_a->array[stack_a->len] = stack_a->array[stack_a->len - 1];
		stack_a->len--;
	}
	stack_a->array[stack_a->len] = temp;
	printf("rra\n");
}

void	rrb(int *stack_b, int top_b, int len)
{
	int	temp;

	temp = 0;
	temp = stack_b[len - 1];
	while (top_b < len - 1)
	{
		stack_b[len] = stack_b[len - 1];
		len--;
	}
	stack_b[len] = temp;
	printf("rb\n");
}
