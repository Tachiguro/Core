/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:16:40 by jherzog           #+#    #+#             */
/*   Updated: 2024/08/16 01:04:59 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rrotate(t_stack *s_a, int target)
{
	int	r;
	int	rr;
	int	top;

	top = s_a->top;
	rr = 0;
	r = 0;
	while (s_a->array[top] > target)
	{
		r++;
		top--;
	}
	while (s_a->array[rr] > target)
		rr++;
	if (rr < r)
		return (0);
	else
		return (1);
}

void	push_to_b(int chunk, t_stack *s_a, t_stack *s_b)
{
	int i = 0;
	while (chunk >= 0)
	{
		if (s_a->array[s_a->top] > s_a->array[s_a->top - 1]
			&& s_b->array[s_b->top] < s_b->array[s_b->top - 1] && s_b->top > 0)
			ss(s_a, s_b);
		else if (s_a->array[s_a->top] > s_a->array[s_a->top - 1])
			sa(s_a);
		if (s_a->array[s_a->top] <= s_a->mid)
		{
			pb(s_a, s_b);
			i++;
		}
		else if (rrotate(s_a, s_a->mid) == 0 && (s_b->array[s_b->top] > s_b->array[0]
				&& s_b->top > 1 && chunk == s_a->chunks_len - 1))
			rrr(s_a, s_b);
		else if (rrotate(s_a, s_a->mid) == 0)
			rra(s_a);
		else if (s_b->array[s_b->top] < s_b->array[0] && s_b->top > 1
				 && chunk == s_a->chunks_len - 1)
			rr(s_a, s_b);
		else
			ra(s_a);
		if (s_a->chunks[chunk] <= i)
		{
			chunk--;
			if (chunk < 0 || (s_a->chunks[chunk] == 0))
				break ;
			s_a->mid = find_mid(s_a->array, 0, s_a->top);
			i = 0;
			if (chunk == 0)
				s_a->chunks[0] += s_a->chunk_remainer;
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
	{
		if (s_a->array[s_a->top] > s_a->array[s_a->top - 1]
			&& s_b->array[s_b->top] < s_b->array[s_b->top - 1])
			ss(s_a, s_b);
		else if (s_a->array[1] > s_a->array[0])
			sa(s_a);
		if (s_b_sorted(s_b) && s_a_sorted(s_a))
		{
			while (s_b->top >= 0)
				pa(s_a, s_b);
			return ;
		}
	}
	chunk = 0;
	while (s_a->chunks[chunk] > 0)
	{
		if (s_b->array[s_b->top] < s_b->array[s_b->top - 1])
			sb(s_b);
		if (s_b->array[s_b->top] == s_b->max && s_a->chunks[chunk] > 0)
		{
			pa(s_a, s_b);
			s_a->chunks[chunk]--;
		}
		else if (rrotate(s_b, s_b->max) == 0)
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
		if (rotations == s_a->chunks[chunk])
			while (rotations > 0)
			{
				rrb(s_b);
				rotations--;
			}
		if (s_a->chunks[chunk] <=  0)
			chunk++;
	}
}
