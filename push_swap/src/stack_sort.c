/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:16:40 by jherzog           #+#    #+#             */
/*   Updated: 2024/08/25 20:23:35 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate_to_top(t_stack *s_b, int target)
{
	int r = 0;
	int rr = 0;
	int index;

	index = s_b->top;
	while (s_b->array[index] != target)
	{
		index--;
		r++;
		if (index < 0)
			index = s_b->top;
	}
	index = 0;
	while (s_b->array[index] != target)
	{
		index++;
		rr++;
		if (index > s_b->top)
			index = 0;
	}
	if (r <= rr)
		return 1;
	else
		return 0;
}

int rotate_between(t_stack *s_b, int target)
{
	int r = 0;
	int rr = 0;
	int index_top;
	int index_bot;

	index_top = s_b->top;
	index_bot = 0;
	int safety_counter = 0;
	int max_iterations = s_b->top + 1;
	while (!(s_b->array[index_top] > target && s_b->array[index_bot] < target))
	{
		index_top--;
		index_bot++;
		if (index_top < 0)
			index_top = s_b->top;
		if (index_bot > s_b->top)
			index_bot = 0;
		r++;
		safety_counter++;
		if (safety_counter > max_iterations)
			break;
	}
	index_top = 0;
	index_bot = s_b->top;
	safety_counter = 0;
	while (!(s_b->array[index_top] > target && s_b->array[index_bot] < target))
	{
		index_top++;
		index_bot--;
		if (index_top > s_b->top)
			index_top = 0;
		if (index_bot < 0)
			index_bot = s_b->top;
		rr++;
		safety_counter++;
		if (safety_counter > max_iterations)
			break;
	}
	if (r <= rr)
		return 1;
	else
		return 0;
}


void	sort(t_stack *s_a, t_stack *s_b)
{
	pb(s_a, s_b);
	pb(s_a, s_b);
	while (s_a->top >= 0)
	{
		if (s_a->array[s_a->top] < s_b->min || s_a->array[s_a->top] > s_b->max)
		{
			if (rotate_to_top(s_b, s_b->max) == 1)
			{
				while (s_b->array[s_b->top] != s_b->max)
					rb(s_b);
				pb(s_a, s_b);
			}
			else
			{
				while (s_b->array[0] != s_b->min)
					rrb(s_b);
				pb(s_a, s_b);
			}

		}
		else
		{
			if (rotate_between(s_b, s_a->array[s_a->top]) == 1)
			{
				while (!(s_a->array[s_a->top] > s_b->array[s_b->top] &&
						s_a->array[s_a->top] < s_b->array[0]))
					rb(s_b);
				pb(s_a, s_b);
			}
			else
			{
				while (!(s_a->array[s_a->top] > s_b->array[s_b->top] &&
						s_a->array[s_a->top] < s_b->array[0]))
					rrb(s_b);
				pb(s_a, s_b);
			}
		}
	}
	if (rotate_to_top(s_b, s_b->max) == 1)
		while (s_b->array[s_b->top] != s_b->max)
			rb(s_b);
	else
		while (s_b->array[s_b->top] != s_b->max)
			rrb(s_b);
	while (s_b->top >= 0)
		pa(s_a, s_b);
}
