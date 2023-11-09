/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirzaza <emirzaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:37:21 by emirzaza          #+#    #+#             */
/*   Updated: 2023/07/09 21:53:07 by emirzaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list **stack_a)
{
	t_list	*temp;
	int		max;
	int		max_bits;

	temp = *stack_a;
	max = temp->index;
	max_bits = 0;
	while (temp != NULL)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	check_next_bit(t_list **stack_a, t_list	**stack_b, int i)
{
	int		j;
	t_list	*temp;
	int		size;

	j = 0;
	size = ft_lstsize(*stack_b);
	while (j++ < size)
	{
		temp = *stack_b;
		if (((temp->index >> i) & 1) == 0)
			rb(stack_b);
		else
		{
			pa(stack_a, stack_b);
		}
	}
}

void	radix(t_list **stack_a, t_list	**stack_b)
{
	int		size;
	int		max_bits;
	int		i;
	int		j;
	t_list	*temp;

	max_bits = get_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = ft_lstsize(*stack_a);
		while (j++ < size && !is_sorted(stack_a))
		{
			temp = *stack_a;
			if (((temp->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		i++;
		check_next_bit(stack_a, stack_b, i);
	}
	while (ft_lstsize(*stack_b) != 0)
		pa(stack_a, stack_b);
}
