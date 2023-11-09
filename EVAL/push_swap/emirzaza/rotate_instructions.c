/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirzaza <emirzaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:43:14 by emirzaza          #+#    #+#             */
/*   Updated: 2023/07/03 16:04:50 by emirzaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_list **stack_a)
{
	t_list	*last;
	t_list	*old;

	if (ft_lstsize(*stack_a) < 2)
		return (-1);
	ft_putendl_fd("ra", 1);
	old = *stack_a;
	*stack_a = (*stack_a)->next;
	old->next = NULL;
	last = ft_lstlast(*stack_a);
	last -> next = old;
	return (0);
}

int	rb(t_list **stack_b)
{
	t_list	*last;
	t_list	*old;

	if (ft_lstsize(*stack_b) < 2)
		return (-1);
	ft_putendl_fd("rb", 1);
	old = *stack_b;
	*stack_b = (*stack_b)->next;
	old->next = NULL;
	last = ft_lstlast(*stack_b);
	last -> next = old;
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	ra(stack_a);
	rb(stack_b);
	return (0);
}
