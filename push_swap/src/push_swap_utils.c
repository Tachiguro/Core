/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:35:38 by jherzog           #+#    #+#             */
/*   Updated: 2024/08/12 20:58:21 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacks(t_stack *s_a, t_stack *s_b)
{
	int	a;
	int	b;
	int	max;

	a = s_a->top;
	b = s_b->top;
	if (a > b)
		max = a;
	else
		max = b;
	write(1, "---------\n", 10);
	while (max >= 0)
	{
		if (a >= 0 && a == max)
			ft_putnbr_fd(s_a->array[a--], 1);
		write(1, "\t", 1);
		if (b >= 0 && b == max)
			ft_putnbr_fd(s_b->array[b--], 1);
		max--;
		write(1, "\n", 1);
	}
	write(1, "---------\n", 10);
	write(1, "a\tb\n", 4);
}

bool	s_a_sorted(t_stack *s_a)
{
	int	i;

	i = s_a->top;
	while (i > 0)
	{
		if (s_a->array[i] > s_a->array[i - 1])
			return (false);
		i--;
	}
	return (true);
}

bool	s_b_sorted(t_stack *s_b)
{
	int	i;

	if (s_b->top == -1 || s_b->top == 0)
		return (true);
	i = 0;
	while (i < s_b->top)
	{
		if (s_b->array[i + 1] < s_b->array[i])
			return (false);
		i++;
	}
	return (true);
}
