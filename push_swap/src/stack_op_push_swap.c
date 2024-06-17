/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:18:11 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/17 19:06:45 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	s_a(t_stack *stack)
{
	int	temp;

	temp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = temp;
	printf("sa\n");
}

void	s_b(t_stack *stack)
{
	int	temp;

	temp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = temp;
	printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	s_a(stack_a);
	s_b(stack_b);
	printf("ss\n");
}

void	p_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top == 0)
		return ;
	stack_a->top++;
	stack_a->array[stack_a->top - 1] = stack_b->array[stack_b->top - 1];
	stack_b->top--;
	printf("pa\n");
}

void	p_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top < 0)
		return ;
	stack_b->array[++(stack_b->top)] = stack_a->array[(stack_a->top)--];
	write(1, "pb\n", 3);
}
