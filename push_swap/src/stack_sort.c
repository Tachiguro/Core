/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:16:40 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/17 22:45:02 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->len = stack_a->top;
	stack_b->array = (int *)malloc(sizeof(int) * stack_a->top);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	ra(stack_a);
	rb(stack_b);
}
