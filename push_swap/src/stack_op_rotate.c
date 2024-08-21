/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:15:16 by jherzog           #+#    #+#             */
/*   Updated: 2024/08/22 00:02:15 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *s_a)
{
	int	temp;
	int	i;

	if (s_a->top < 1)
		return ;
	temp = s_a->array[s_a->top];
	i = s_a->top;
	while (i > 0)
	{
		s_a->array[i] = s_a->array[i - 1];
		i--;
	}
	s_a->array[0] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *s_b)
{
	int	temp;
	int	i;

	if (s_b->top < 1)
		return ;
	temp = s_b->array[s_b->top];
	i = s_b->top;
	while (i > 0)
	{
		s_b->array[i] = s_b->array[i - 1];
		i--;
	}
	s_b->array[0] = temp;
	write(1, "rb\n", 3);
}

void	rra(t_stack *s_a)
{
	int	temp;
	int	i;

	if (s_a->top < 1)
		return ;
	temp = s_a->array[0];
	i = 0;
	while (i < s_a->top)
	{
		s_a->array[i] = s_a->array[i + 1];
		i++;
	}
	s_a->array[s_a->top] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *s_b)
{
	int	temp;
	int	i;

	if (s_b->top < 1)
		return ;
	temp = s_b->array[0];
	i = 0;
	while (i < s_b->top)
	{
		s_b->array[i] = s_b->array[i + 1];
		i++;
	}
	s_b->array[s_b->top] = temp;
	write(1, "rrb\n", 4);
}
