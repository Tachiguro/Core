/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:16:40 by jherzog           #+#    #+#             */
/*   Updated: 2024/08/29 00:39:36 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_b(int chunk, t_stack *s_a, t_stack *s_b)
{
	int	i;

	i = 0;
	s_a->max_chunk = find_max_chunk(s_a, chunk);
	while (chunk >= 0)
	{
		if (s_a->array[s_a->top] <= s_a->max_chunk)
		{
			pb(s_a, s_b);
			i++;
		}
		else if ((s_b->array[s_b->top] < s_b->array[0]
				&& s_b->top > 0) && rrotate_to_mid(s_a, s_a->max_chunk) == 1)
			rrr(s_a, s_b);
		else if (rrotate_to_mid(s_a, s_a->max_chunk) == 1)
			rra(s_a);
		else if (s_b->array[s_b->top] < s_b->array[0] && s_b->top > 0)
			rr(s_a, s_b);
		else if (s_a->array[s_a->top - 1] <= s_a->max_chunk && s_b->array[s_b->top] < s_b->array[s_b->top - 1]  && s_b->top > 0)
			ss(s_a, s_b);
		else
			ra(s_a);
		if (s_a->chunks[chunk] <= i)
		{
			i = 0;
			chunk--;
			s_a->max_chunk = find_max_chunk(s_a, chunk);
		}
	}
}

void	sort(t_stack *s_a, t_stack *s_b)
{
	int	chunk;
	int	rotations;

	rotations = 0;
	push_to_b(s_a->chunks_len - 1, s_a, s_b);
	if (!s_a_sorted(s_a))
		sort_three(s_a);
	chunk = 0;
	while (s_a->chunks[chunk] > 0)
	{
		if (s_b->array[s_b->top] == s_b->max && s_a->chunks[chunk] > 0)
		{
			pa(s_a, s_b);
			s_a->chunks[chunk]--;
			while (rotations > 0 && s_b->top > 0 && rrotate_to_max(s_b, s_b->max) == 1 && s_a->chunks_len -1 != chunk)
			{
				if (s_b->array[s_b->top] == s_b->max)
				{
					pa(s_a, s_b);
					s_a->chunks[chunk]--;
				}
				rrb(s_b);
				rotations--;
			}
			while (rotations < 0 && s_b->top > 0 && s_a->chunks_len -1 != chunk)
			{
				if (s_b->array[s_b->top] == s_b->max)
				{
					pa(s_a, s_b);
					s_a->chunks[chunk]--;
				}
				rb(s_b);
				rotations++;
			}
		}
		else if (rrotate_to_max(s_b, s_b->max) == 1)
		{
			rrb(s_b);
			rotations--;
		}
		else
		{
			rb(s_b);
			rotations++;
		}
		if (s_b->top == -1)
			break ;
		if (s_a->chunks[chunk] <=  0)
			chunk++;
	}
}
