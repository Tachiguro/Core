/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:16:40 by jherzog           #+#    #+#             */
/*   Updated: 2024/08/22 00:18:49 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stack *s_a, t_stack *s_b)
{
	pb(s_a, s_b);
	while (s_a->top >= 0)
	{
		if (s_a->array[s_a->top] < s_b->array[s_b->top])
		{
			pb(s_a, s_b);
			rb(s_b);
		}
		else
			pb(s_a, s_b);
	}
	while (s_b->top >= 0)
	{
		pa(s_a, s_b);
	}

}
