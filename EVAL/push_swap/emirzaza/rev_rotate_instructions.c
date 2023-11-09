/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirzaza <emirzaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:40:41 by emirzaza          #+#    #+#             */
/*   Updated: 2023/07/03 16:05:16 by emirzaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*new_last;

	if (ft_lstsize(*stack_a) < 2)
		return (-1);
	ft_putendl_fd("rra", 1);
	last = *stack_a;
	while (last != NULL)
	{
		if (last-> next == NULL)
			break ;
		new_last = last;
		last = last -> next;
	}
	new_last -> next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	return (0);
}

int	rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*new_last;

	if (ft_lstsize(*stack_b) < 2)
		return (-1);
	ft_putendl_fd("rrb", 1);
	last = *stack_b;
	while (last != NULL)
	{
		if (last-> next == NULL)
			break ;
		new_last = last;
		last = last -> next;
	}
	new_last -> next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	rra(stack_a);
	rrb(stack_b);
	return (0);
}
