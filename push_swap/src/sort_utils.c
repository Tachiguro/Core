/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 00:30:11 by jherzog           #+#    #+#             */
/*   Updated: 2024/08/30 00:45:55 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack *s_a)
{
	int top;
	int mid;
	int bottom;

	top = s_a->array[s_a->top];
	mid = s_a->array[s_a->top - 1];
	bottom = s_a->array[s_a->top - 2];
	if (mid < bottom && bottom > top)
		sa(s_a);
	else if (top > mid && mid > bottom)
	{
		sa(s_a);
		rra(s_a);
	}
	else if (top > bottom && bottom > mid)
		ra(s_a);
	else if (bottom > top && mid > top)
	{
		sa(s_a);
		ra(s_a);
	}
	else if (mid > top && top > bottom)
		rra(s_a);
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

int	rrotate_to_target(t_stack *s_a, int target)
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
	if (rr < r )
		return (1);
	else if (rr == r && s_a->array[rr] < s_a->array[top])
			return (1);
	else
		return (0);
}
