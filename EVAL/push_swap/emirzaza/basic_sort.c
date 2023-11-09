/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirzaza <emirzaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:04:56 by emirzaza          #+#    #+#             */
/*   Updated: 2023/07/11 13:25:12 by emirzaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_max(t_list *stack)
{
	t_list	*max;

	max = NULL;
	while (stack)
	{
		if (!max || max->index < stack->index)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_list	*get_min(t_list *stack)
{
	t_list	*min;

	min = NULL;
	while (stack)
	{
		if (!min || min->index > stack->index)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	get_at(t_list *stack, int index)
{
	int		i;

	i = 0;
	while (stack)
	{
		if (i == index)
			return (stack->index);
		i++;
		stack = stack->next;
	}
	return (-1);
}

void	push_firsts_to_b(t_list	**stack_a, t_list	**stack_b)
{
	while (ft_lstsize(*stack_a) > 3 && ft_lstsize(*stack_a) < 7)
	{
		while ((*stack_a)->index != get_min(*stack_a)->index)
		{
			ra(stack_a);
		}
		pb(stack_a, stack_b);
	}
}

void	sort_small(t_list	**stack_a, t_list	**stack_b)
{
	push_firsts_to_b(stack_a, stack_b);
	if (get_min(*stack_a)->index == get_at(*stack_a, 1)
		&& get_max(*stack_a)->index == get_at(*stack_a, 2))
		sa(stack_a);
	if (get_min(*stack_a)->index == get_at(*stack_a, 1)
		&& get_max(*stack_a)->index == get_at(*stack_a, 0))
		ra(stack_a);
	if (get_min(*stack_a)->index == get_at(*stack_a, 2)
		&& get_max(*stack_a)->index == get_at(*stack_a, 1))
		rra(stack_a);
	if (get_min(*stack_a)->index == get_at(*stack_a, 0)
		&& get_max(*stack_a)->index == get_at(*stack_a, 1))
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (get_min(*stack_a)->index == get_at(*stack_a, 2)
		&& get_max(*stack_a)->index == get_at(*stack_a, 0))
	{
		sa(stack_a);
		rra(stack_a);
	}
	while (ft_lstsize(*stack_b))
		pa(stack_a, stack_b);
}
