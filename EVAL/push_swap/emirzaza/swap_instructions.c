/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirzaza <emirzaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:57:09 by emirzaza          #+#    #+#             */
/*   Updated: 2023/06/22 16:47:33 by emirzaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		temp_value;
	int		temp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head -> next;
	if (!head || !next)
		ft_error("Error occured while swapping.");
	temp_value = head -> content;
	temp_index = head -> index;
	head -> content = next -> content;
	head -> index = next -> index;
	next -> content = temp_value;
	next -> index = temp_index;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	sa(stack_a);
	sb(stack_b);
	return (0);
}
