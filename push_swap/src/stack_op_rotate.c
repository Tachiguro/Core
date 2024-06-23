/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:15:16 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/23 21:15:05 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
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

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
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

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
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

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
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
