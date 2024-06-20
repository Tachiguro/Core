/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:16:40 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/20 03:53:16 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stack *s_a, t_stack *s_b)
{
	char direction;

	direction = 'u';
	while (!stack_a_sorted(s_a))
	{
		if (s_a->array[s_a->top] > s_a->array[s_a->top - 1])
			sa(s_a);
		else if (!(s_a->array[s_a->top - 1] == s_a->max) && direction == 'u')
		{
			ra(s_a);
			if (s_a->array[s_a->top - 1] == s_a->max)
				direction = 'd';
		}
		else
		{
			rra(s_a);
			if (s_a->array[0] == s_a->max)
				direction = 'u';
		}
	}
}

