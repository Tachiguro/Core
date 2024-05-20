/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:15:16 by jherzog           #+#    #+#             */
/*   Updated: 2024/05/20 21:21:35 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(int *stack_a, int top_a, int len)
{
	int	temp;

	temp = 0;
	temp = stack_a[top_a];
	while (top_a < len - 1)
	{
		stack_a[top_a] = stack_a[top_a + 1];
		top_a++;
	}
	stack_a[top_a] = temp;
	printf("ra\n");
}

void	rb(int *stack_b, int top_b, int len)
{
	int	temp;

	temp = 0;
	temp = stack_b[top_b];
	while (top_b < len - 1)
	{
		stack_b[top_b] = stack_b[top_b];
		top_b++;
	}
	stack_b[top_b] = temp;
	printf("rb\n");
}

void	rra(int *stack_a, int top_a, int len)
{
	int	temp;

	temp = 0;
	temp = stack_a[len - 1];
	while (top_a < len - 1)
	{
		stack_a[len] = stack_a[len - 1];
		len--;
	}
	stack_a[len] = temp;
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


// rrr : rra and rrb at the same time.

// rr : ra and rb at the same time.
