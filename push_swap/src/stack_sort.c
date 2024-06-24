/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:16:40 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/24 21:01:55 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stack *s_a, t_stack *s_b)
{
	int	chunk;
	int	i;

	chunk = 0;
	i = 0;
	while (!s_a_sorted(s_a) || s_a->top != s_a->len - 1)
	{
		while (s_a->chunks[chunk] >= i)
		{
			if (s_a->array[s_a->top] < s_a->mid)
			{
				pb(s_a, s_b);
				i++;
			}
			else if (s_b->top > 0 && s_a->array[0] < s_a->array[s_a->top]
					&& s_b->array[0] > s_b->array[s_b->top])
				rrr(s_a, s_b);
			else if (s_a->array[0] < s_a->mid)
				rra(s_a);
			else if (s_b->array[s_b->top] < s_b->top - 1)
				rr(s_a, s_b);
			else if (s_a->array[0] > s_a->mid || s_a->array[0] < s_a->array[s_a->top])
				ra(s_a);
			if (s_a->chunks[chunk] <= i)
			{
				chunk++;
				find_mid(s_a);
				i = 0;
			}
		}
		if (s_b_sorted(s_b) && s_a_sorted(s_a))
			while (s_b->top >= 0)
				pa(s_a, s_b);
		else
		{
			chunk = 0;
			i = s_a->chunks[chunk];
			while (s_a->chunks[chunk] >= i)
			{
				while (s_b->array[s_b->top] == s_b->max)
				{
					pa(s_a, s_b);
					i--;
				}
				if (s_b->top == -1)
					break ;
				if (s_b->array[0] == s_b->max)
					rrb(s_b);
				else
					rb(s_b);
				if (s_a->chunks[chunk] <= i)
				{
					chunk++;
					find_mid(s_a);
					i = s_a->chunks[chunk];
				}
			}
		}
	}
}
