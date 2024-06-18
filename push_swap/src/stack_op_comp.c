/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_comp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:10:09 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/18 16:14:36 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ss : sa and sb at the same time.
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	temp = stack_a->array[0];
	stack_a->array[0] = stack_a->array[1];
	stack_a->array[1] = temp;
	temp = stack_b->array[0];
	stack_b->array[0] = stack_b->array[1];
	stack_b->array[1] = temp;
	printf("ss\n");
}

// rr : ra and rb at the same time.
void	rr(t_stack *stack_a, t_stack *stack_b)
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
	printf("rr\n");
}

// rrr : rra and rrb at the same time.
// to check
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;
	int	i;

	i = 0;
	if (stack_a->top < 1)
		return ;
	temp = stack_a->array[0];
	while (i < stack_a->top)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
	stack_a->array[stack_a->top] = temp;
	i = 0;
	if (stack_b->top < 1)
		return ;
	temp = stack_b->array[0];
	while (i < stack_b->top)
	{
		stack_b->array[i] = stack_b->array[i + 1];
		i++;
	}
	stack_b->array[stack_b->top] = temp;
	printf("rrr\n");
}
