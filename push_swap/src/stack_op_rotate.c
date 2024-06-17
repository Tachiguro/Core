/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:15:16 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/17 23:16:22 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


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

// to fix
void	rra(t_stack *stack_a)
{
	int	temp;
	int	i;

	i = 0;
	if (stack_a->top < 1)
		return ;
	temp = stack_a->array[stack_a->top];
	while (i < stack_a->top)
	{
		stack_a->array[i] = stack_a->array[i - 1];
		i--;
	}
	stack_a->array[0] = temp;
	write(1, "rra\n", 4);
}

// to fix
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
