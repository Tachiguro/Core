/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:40:04 by wrottger          #+#    #+#             */
/*   Updated: 2023/07/14 11:25:43 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(struct s_stacks *stacks)
{
	if (0 < stacks->a_size)
	{
		stacks->b[stacks->b_size] = stacks->a[stacks->a_size - 1];
		stacks->a[stacks->a_size - 1] = 0;
		stacks->a_size--;
		stacks->b_size++;
	}
	write(1, "pb\n", 3);
}

void	pa(struct s_stacks *stacks)
{
	if (0 < stacks->b_size)
	{
		stacks->a[stacks->a_size] = stacks->b[stacks->b_size - 1];
		stacks->b[stacks->b_size - 1] = 0;
		stacks->b_size--;
		stacks->a_size++;
	}
	write(1, "pa\n", 3);
}

void	ra(struct s_stacks *stacks)
{
	size_t	i;

	i = 1;
	while (i < stacks->a_size)
	{
		swap(&stacks->a[i], &stacks->a[0]);
		i++;
	}
	write(1, "ra\n", 3);
}
