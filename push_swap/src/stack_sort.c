/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:16:40 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/25 03:52:48 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void sort_s_a_trhee(t_stack *s_a)
{
	if (s_a->array[2] < s_a->array[1] && s_a->array[1] > s_a->array[0]) // 132
	{
		sa(s_a);
		ra(s_a);
	}
	else if (s_a->array[2] > s_a->array[1] && s_a->array[1] < s_a->array[0]) // 213
	{
		sa(s_a);
	}
	else if (s_a->array[2] > s_a->array[1] && s_a->array[1] > s_a->array[0]) // 231
	{
		rra(s_a);
	}
	else if (s_a->array[2] < s_a->array[1] && s_a->array[1] > s_a->array[0]) // 312
	{
		ra(s_a);
	}
	else if (s_a->array[2] < s_a->array[1] && s_a->array[1] < s_a->array[0]) // 321
	{
		ra(s_a);
		sa(s_a);
	}
}

void	sort(t_stack *s_a, t_stack *s_b)
{
	int	chunk;
	int	i;

	chunk = 0;
	i = 0;
	while (s_a->chunks[chunk] >= i)
	{
		if (s_a->array[s_a->top] < s_a->mid)
		{
			pb(s_a, s_b);
			i++;
		}
		else if (s_a->array[0] < s_a->mid)
			rra(s_a);
		else if (s_b->array[s_b->top] < s_b->array[0])
			rr(s_a, s_b);
		else
			ra(s_a);
		if (s_a->chunks[chunk] < i && s_a->top > 1)
		{
			chunk++;
			find_mid(s_a);
			i = 0;
		}
	}
	if (s_a->top == 2)
		sort_s_a_trhee(s_a);
	if (s_a->array[1] > s_a->array[0])
		ra(s_a);
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
