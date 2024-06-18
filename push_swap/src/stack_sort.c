/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:16:40 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/18 17:53:58 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



void	push_swap(t_stack *s_a, t_stack *s_b)
{
	char	direction;
	int		i;

	i = 0;
	direction = 'u';
	s_b->len = s_a->top;
	s_b->array = (int *)malloc(sizeof(int) * s_a->top);
	if (!s_b->array)
		return ;
	while (!stack_sorted(s_a) && i < 5)
	{
		if (s_a->array[s_a->top] > s_a->array[s_a->top - 1])
			sa(s_a);
		if (s_b->array[s_b->top] > s_b->array[s_b->top - 1])
			sb(s_b);
		if (!(s_a->array[s_a->top - 1] == s_a->max) && direction == 'u')
			ra(s_a);
		else
		{
			rra(s_a);
			direction = 'd';
		}
		if (!(s_a->array[0] == s_a->max) && direction == 'd')
			rra(s_a);
		else
		{
			ra(s_a);
			direction = 'u';
		}
		i++;
	}
}
