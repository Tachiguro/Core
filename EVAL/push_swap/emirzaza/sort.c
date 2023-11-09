/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirzaza <emirzaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:43:50 by emirzaza          #+#    #+#             */
/*   Updated: 2023/07/11 17:26:31 by emirzaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list	**stack_a, t_list	**stack_b)
{
	int	size;

	if (is_sorted(stack_a))
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size < 7)
		sort_small(stack_a, stack_b);
	if (!is_sorted(stack_a))
		radix(stack_a, stack_b);
}

int	is_sorted(t_list	**stack_a)
{
	t_list	*temp;
	int		index;

	temp = *stack_a;
	index = temp->index;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->index < index)
			return (0);
		index = temp->index;
	}
	return (1);
}
