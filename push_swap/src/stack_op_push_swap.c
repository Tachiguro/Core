/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:18:11 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/14 17:17:32 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(int *stack_a)
{
	int	temp;

	temp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = temp;
	printf("sa\n");
}

void	swap_b(int *stack_b)
{
	int	temp;

	temp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = temp;
	printf("sb\n");
}

void	swap_a_and_b(int *stack_a, int *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	printf("ss\n");
}

void	push_a(int *stack_a, int top_a, int *stack_b, int top_b)
{
	top_a--;
	stack_a[top_a] = stack_b[top_b];
	top_b++;
	printf("pa\n");
}

void	push_b(int *stack_a, int top_a, int *stack_b, int top_b)
{
	top_b--;
	stack_b[top_b] = stack_a[top_a];
	top_a++;
	printf("pb\n");
}
