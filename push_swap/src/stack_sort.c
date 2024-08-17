/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:16:40 by jherzog           #+#    #+#             */
/*   Updated: 2024/08/18 01:37:37 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rrotate_to_mid(t_stack *s_a, int target)
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
		return (1);
	else
		return (0);
}

int	rrotate_to_max(t_stack *s_a, int target)
{
	int	r;
	int	rr;
	int	top;

	top = s_a->top;
	rr = 0;
	r = 0;
	while (s_a->array[top] < target)
	{
		r++;
		top--;
	}
	while (s_a->array[rr] < target)
		rr++;
	if (rr < r)
		return (1);
	else
		return (0);
}

void	push_to_b(int chunk, t_stack *s_a, t_stack *s_b)
{
	int	i;

	i = 0;
	s_a->mid = find_mid(s_a->array, 0, s_a->top + 1);
	while (chunk >= 0)
	{
		// if (s_a->array[s_a->top] > s_a->array[s_a->top - 1]
		// 	&& s_b->array[s_b->top] < s_b->array[s_b->top - 1] && s_b->top > 0)
		// 	ss(s_a, s_b);
		// else if (s_a->array[s_a->top] > s_a->array[s_a->top - 1])
		// 	sa(s_a);
		if (s_a->array[s_a->top] <= s_a->mid)
		{
			pb(s_a, s_b);
			i++;
		}
		else if (rrotate_to_mid(s_a, s_a->mid) == 1 && (s_b->array[s_b->top] > s_b->array[0]
				&& s_b->top > 1 && chunk == s_a->chunks_len - 1))
			rrr(s_a, s_b);
		else if (rrotate_to_mid(s_a, s_a->mid) == 1)
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
			i = 0;
			s_a->mid = find_mid(s_a->array, 0, s_a->top + 1);
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
		// if (s_b->array[s_b->top] < s_b->array[s_b->top - 1])
		// 	sb(s_b);
		if (s_b->array[s_b->top] == s_b->max && s_a->chunks[chunk] > 0)
		{
			pa(s_a, s_b);
			s_a->chunks[chunk]--;
			while (rotations > 0 && s_b->top > 0)
			{
				if (s_b->array[s_b->top] == s_b->max && s_a->chunks[chunk] > 0)
					pa(s_a, s_b);
				rrb(s_b);
				rotations--;
			}
			while (rotations < 0 && s_b->top > 0)
			{
				if (s_b->array[s_b->top] == s_b->max && s_a->chunks[chunk] > 0)
					pa(s_a, s_b);
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
