/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:18:11 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/07 23:59:18 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *s_a)
{
	int	temp;

	if (s_a->top < 1)
		return ;
	temp = s_a->array[s_a->top];
	s_a->array[s_a->top] = s_a->array[s_a->top - 1];
	s_a->array[s_a->top - 1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *s_b)
{
	int	temp;

	if (s_b->top < 1)
		return ;
	temp = s_b->array[s_b->top];
	s_b->array[s_b->top] = s_b->array[s_b->top - 1];
	s_b->array[s_b->top - 1] = temp;
	write(1, "sb\n", 3);
}

void	pa(t_stack *s_a, t_stack *s_b)
{
	int	i;

	i = 0;
	if (s_b->top < 0)
		return ;
	s_a->array[++(s_a->top)] = s_b->array[(s_b->top)--];
	s_b->max = INT_MIN;
	while (i <= s_b->top)
	{
		if (s_b->max < s_b->array[i])
			s_b->max = s_b->array[i];
		i++;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack *s_a, t_stack *s_b)
{
	if (s_a->top < 0)
		return ;
	s_b->array[++(s_b->top)] = s_a->array[(s_a->top)--];
	if (s_b->max < s_b->array[s_b->top])
		s_b->max = s_b->array[s_b->top];
	write(1, "pb\n", 3);
}
