/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:35:38 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/08 19:17:15 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	s_a_sorted(t_stack *s_a)
{
	int	i;

	i = s_a->top;
	while (i > 0)
	{
		if (s_a->array[i] > s_a->array[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	s_b_sorted(t_stack *s_b)
{
	int	i;

	if (s_b->top == -1 || s_b->top == 0)
		return (true);
	i = 0;
	while (i < s_b->top)
	{
		if (s_b->array[i + 1] < s_b->array[i])
			return (0);
		i++;
	}
	return (1);
}

void	sort_three(t_stack *s_a)
{
	int	one;
	int	two;
	int	three;

	one = s_a->array[s_a->top];
	two = s_a->array[s_a->top - 1];
	three = s_a->array[s_a->top - 2];
	if (two < one && one < three)
		sa(s_a);
	else if (three < two && two < one)
	{
		sa(s_a);
		rra(s_a);
	}
	else if (two < three && three < one)
		ra(s_a);
	else if (one < three && three < two)
	{
		sa(s_a);
		ra(s_a);
	}
	else
		rra(s_a);
}

int	rr_to_chunk_max(t_stack *s_a, int target)
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
	else if (rr == r && s_a->array[rr] < s_a->array[top])
		return (1);
	else
		return (0);
}

int	rr_to_max(t_stack *s_a, int target)
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
