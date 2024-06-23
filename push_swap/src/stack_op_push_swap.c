/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:18:11 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/24 00:36:33 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_stack *s_a)
{
	int	temp;

	if (s_a->top < 1)
		return ;
	temp = s_a->array[s_a->top];
	s_a->array[s_a->top] = s_a->array[s_a->top - 1];
	s_a->array[s_a->top - 1] = temp;
	printf("sa\n");
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_stack *s_b)
{
	int	temp;

	if (s_b->top < 1)
		return ;
	temp = s_b->array[s_b->top];
	s_b->array[s_b->top] = s_b->array[s_b->top - 1];
	s_b->array[s_b->top - 1] = temp;
	printf("sb\n");
}

// pa push a: Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_stack *s_a, t_stack *s_b)
{
	int	i;

	i = 0;
	if (s_b->top < 0)
		return ;
	s_a->array[++(s_a->top)] = s_b->array[(s_b->top)--];
	s_b->max = INT_MIN;
	while (i < s_b->top)
	{
		if (s_b->max < s_b->array[i])
			s_b->max = s_b->array[i];
		i++;
	}
	printf("pa\n");
}

// pb push b: Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_stack *s_a, t_stack *s_b)
{
	if (s_a->top < 0)
		return ;
	s_b->array[++(s_b->top)] = s_a->array[(s_a->top)--];
	if (s_b->max < s_b->array[s_b->top])
		s_b->max = s_b->array[s_b->top];
	write(1, "pb\n", 3);
}
