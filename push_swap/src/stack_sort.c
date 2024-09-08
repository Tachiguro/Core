/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:16:40 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/08 19:37:49 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_to_b(int chunk, int i, t_stack *s_a, t_stack *s_b)
{
	s_a->chunk_max = find_max_chunk(s_a, chunk);
	while (chunk >= 0)
	{
		if (s_a->array[s_a->top] <= s_a->chunk_max)
		{
			pb(s_a, s_b);
			i++;
		}
		else if (rr_to_chunk_max(s_a, s_a->chunk_max) == 1
			&& (s_b->array[s_b->top] < s_b->array[0] && s_b->top > 0))
			rrr(s_a, s_b);
		else if (rr_to_chunk_max(s_a, s_a->chunk_max) == 1)
			rra(s_a);
		else if (s_b->array[s_b->top] < s_b->array[0] && s_b->top > 0)
			rr(s_a, s_b);
		else
			ra(s_a);
		if (s_a->chunks[chunk] <= i)
		{
			chunk--;
			s_a->chunk_max = find_max_chunk(s_a, chunk);
			i = 0;
		}
	}
}

static int	helper(int r, int chunk, t_stack *s_a, t_stack *s_b)
{
	while (rr_to_max(s_b, s_b->max) == 1 && s_a->chunks_len -1 != chunk
		&& r > 0 && s_b->top > 0)
	{
		if (s_b->array[s_b->top] == s_b->max)
		{
			pa(s_a, s_b);
			s_a->chunks[chunk]--;
		}
		rrb(s_b);
		r--;
	}
	while (r < 0 && s_b->top > 0 && s_a->chunks_len -1 != chunk)
	{
		if (s_b->array[s_b->top] == s_b->max)
		{
			pa(s_a, s_b);
			s_a->chunks[chunk]--;
		}
		rb(s_b);
		r++;
	}
	return (r);
}

static void	push_back_to_a(t_stack *s_a, t_stack *s_b, int chunk, int r)
{
	if (s_b->array[s_b->top] == s_b->max && s_a->chunks[chunk] > 0)
	{
		pa(s_a, s_b);
		s_a->chunks[chunk]--;
		r = helper(r, chunk, s_a, s_b);
	}
	else if (rr_to_max(s_b, s_b->max) == 1)
	{
		rrb(s_b);
		r--;
	}
	else
	{
		rb(s_b);
		r++;
	}
}

void	sort(t_stack *s_a, t_stack *s_b)
{
	int	r;
	int	chunk;

	r = 0;
	chunk = 0;
	push_to_b(s_a->chunks_len - 1, chunk, s_a, s_b);
	if (!s_a_sorted(s_a))
		sort_three(s_a);
	while (s_a->chunks[chunk] > 0)
	{
		push_back_to_a(s_a, s_b, chunk, r);
		if (s_b->top == -1)
			break ;
		if (s_a->chunks[chunk] <= 0)
			chunk++;
	}
}
