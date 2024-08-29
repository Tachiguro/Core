/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:11:47 by jherzog           #+#    #+#             */
/*   Updated: 2024/08/29 22:14:21 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fake_rrr(t_stack *s_a, t_stack *s_b)
{
	int	temp;
	int	i;

	i = 0;
	if (s_a->top < 1)
		return ;
	temp = s_a->array[0];
	while (i < s_a->top)
	{
		s_a->array[i] = s_a->array[i + 1];
		i++;
	}
	s_a->array[s_a->top] = temp;
	i = 0;
	if (s_b->top < 1)
		return ;
	temp = s_b->array[0];
	while (i < s_b->top)
	{
		s_b->array[i] = s_b->array[i + 1];
		i++;
	}
	s_b->array[s_b->top] = temp;
}
void	fake_rra(t_stack *s_a)
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
}

void	fake_rr(t_stack *s_a, t_stack *s_b)
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
}
void	fake_ss(t_stack *s_a, t_stack *s_b)
{
	int	temp;

	temp = s_a->array[s_a->top];
	s_a->array[s_a->top] = s_a->array[s_a->top - 1];
	s_a->array[s_a->top - 1] = temp;

	temp = s_b->array[s_b->top];
	s_b->array[s_b->top] = s_b->array[s_b->top - 1];
	s_b->array[s_b->top - 1] = temp;
}
void	fake_ra(t_stack *s_a)
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
}
