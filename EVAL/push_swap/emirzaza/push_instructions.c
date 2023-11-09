/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirzaza <emirzaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:43:17 by emirzaza          #+#    #+#             */
/*   Updated: 2023/07/11 14:47:12 by emirzaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*temp;

	temp = *stack_from;
	*stack_from = (*stack_from)->next;
	temp->next = NULL;
	if (*stack_to && (*stack_to)->index != -1)
		temp->next = *stack_to;
	*stack_to = temp;
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	ft_putendl_fd("pa", 1);
	push(stack_a, stack_b);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	ft_putendl_fd("pb", 1);
	push(stack_b, stack_a);
	return (0);
}
