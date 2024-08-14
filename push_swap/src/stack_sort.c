/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:16:40 by jherzog           #+#    #+#             */
/*   Updated: 2024/08/14 22:58:25 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_b(int chunk, t_stack *s_a, t_stack *s_b) {
	int i = 0;

	while (chunk >= 0)
	{
		if (s_a->array[s_a->top] <= s_a->mid)
		{
			pb(s_a, s_b);
			i++;
		}
		else if (s_a->array[0] < s_a->mid && s_b->array[0] > s_b->top)
			rrr(s_a, s_b);
		else if (s_a->array[0] < s_a->mid)
			rra(s_a);
		else if (s_b->array[s_b->top] < s_b->array[0])
			rr(s_a, s_b);
		else
			ra(s_a);
		if (s_a->chunks[chunk] < i)
		{
			chunk--;
			if (chunk < 0 || (s_a->chunks[chunk] == 0))
				break ;
			s_a->mid = find_mid(s_a->array, 0, s_a->top);
			i = 0;
		}
	}
}

void	sort(t_stack *s_a, t_stack *s_b)
{
	int	chunk;
	int	i;

	i = 0;
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
	i = -1;
	while (s_a->chunks[chunk] > i)
	{
		while (s_b->array[s_b->top] == s_b->max && s_a->chunks[chunk] > i)
		{
			pa(s_a, s_b);
			i++;
		}
		if (s_b->top == -1)
			break ;
		if (s_b->array[s_b->top] < s_b->array[s_b->top - 1])
			sb(s_b);
		else if (s_b->array[0] == s_b->max)
			rrb(s_b);
		else
			rb(s_b);
		if (s_a->chunks[chunk] <=  i)
		{
			chunk++;
			s_a->chunk_mid = find_mid(s_b->array, s_a->top - s_a->chunks_len, s_a->top);
			i = -1;
		}
	}
}
