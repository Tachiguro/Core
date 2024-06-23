/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:16:40 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/24 00:41:22 by jherzog          ###   ########.fr       */
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

void	sort_b(t_stack *s_a, t_stack *s_b)
{
	if (s_b->array[s_b->top] == s_b->max)
		pa(s_a, s_b);
	else
		rb(s_b);
}

void	sort(t_stack *s_a, t_stack *s_b)
{
	while (!s_a_sorted(s_a) || s_a->top != s_a->len - 1)
	{
		if (s_a->top == 2 && !s_a_sorted(s_a))
			sort_s_a_trhee(s_a);
		else if (s_b_sorted(s_b) && s_a_sorted(s_a))
		{
			while (s_b->top >= 0)
				pa(s_a, s_b);
		}
		else if (s_a_sorted(s_a) && !s_b_sorted(s_b))
			sort_b(s_a, s_b);
		else if (s_a->array[s_a->top] > s_a->array[s_a->top - 1])
			sa(s_a);
		else if (s_a->array[s_a->top] < s_a->mid)
			pb(s_a, s_b);
		else
			rra(s_a);
	// print_stacks(s_a, s_b);
	}
	// print_stacks(s_a, s_b);
}
