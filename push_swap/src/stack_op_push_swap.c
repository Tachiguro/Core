/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:18:11 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/17 23:11:31 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->array[0];
	stack_a->array[0] = stack_a->array[1];
	stack_a->array[1] = temp;
	printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	int	temp;

	temp = stack_b->array[0];
	stack_b->array[0] = stack_b->array[1];
	stack_b->array[1] = temp;
	printf("sb\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top < 0)
		return ;
	stack_a->array[++(stack_a->top)] = stack_b->array[(stack_b->top)--];
	printf("pa\n");
}

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
