/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:38:11 by wrottger          #+#    #+#             */
/*   Updated: 2023/07/12 18:35:33 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_leftstack(struct s_stacks stacks)
{
	if (stacks.a[2] > stacks.a[1] && stacks.a[1] < stacks.a[0]
		&& stacks.a[2] < stacks.a[0])
		write(1, "sa\n", 3);
	if (stacks.a[2] < stacks.a[1] && stacks.a[1] > stacks.a[0]
		&& stacks.a[2] < stacks.a[0])
		write(1, "rra\nsa\n", 7);
	if (stacks.a[2] < stacks.a[1] && stacks.a[1] > stacks.a[0]
		&& stacks.a[2] > stacks.a[0])
		write(1, "rra\n", 4);
	if (stacks.a[2] > stacks.a[1] && stacks.a[1] < stacks.a[0]
		&& stacks.a[2] > stacks.a[0])
		write(1, "ra\n", 3);
	if (stacks.a[2] > stacks.a[1] && stacks.a[1] > stacks.a[0]
		&& stacks.a[2] > stacks.a[0])
		write(1, "sa\nrra\n", 7);
}

static void	sort_rightstack(struct s_stacks stacks)
{
	if (stacks.b[0] == 3 && stacks.b[1] == 1)
		write(1, "sb\n", 3);
	if (stacks.b[0] == 2 && stacks.b[1] == 3)
		write(1, "rrb\nsb\n", 7);
	if (stacks.b[0] == 1 && stacks.b[1] == 3)
		write(1, "rrb\n", 4);
	if (stacks.b[0] == 2 && stacks.b[1] == 1)
		write(1, "rb\n", 3);
	if (stacks.b[0] == 1 && stacks.b[1] == 2)
		write(1, "sb\nrrb\n", 7);
}

void	sort_middle(struct s_stacks stacks)
{
	while (stacks.a_size > 3)
	{
		if (stacks.a[stacks.a_size - 1] <= (int)(stacks.size - 3))
			pb(&stacks);
		else
			ra(&stacks);
	}
	sort_rightstack(stacks);
	sort_leftstack(stacks);
	if (stacks.b_size == 3)
		write(1, "sb\nrrb\n", 7);
	while (stacks.b_size > 0)
		pa(&stacks);
}

void	sort_three(struct s_stacks stacks)
{
	if (stacks.a[2] == 2 && stacks.a[1] == 1)
		write(1, "sa\n", 3);
	if (stacks.a[2] == 1 && stacks.a[1] == 3)
		write(1, "rra\nsa\n", 7);
	if (stacks.a[2] == 2 && stacks.a[1] == 3)
		write(1, "rra\n", 4);
	if (stacks.a[2] == 3 && stacks.a[1] == 1)
		write(1, "ra\n", 3);
	if (stacks.a[2] == 3 && stacks.a[1] == 2)
		write(1, "sa\nrra\n", 7);
}

void	sort_stacks(struct s_stacks stacks)
{
	int		curr_bit;
	size_t	i;

	curr_bit = 0;
	while (curr_bit < count_bits(stacks.size))
	{
		i = 0;
		while (i < stacks.size)
		{
			if ((stacks.a[stacks.a_size - 1] >> curr_bit) % 2 == 0)
				pb(&stacks);
			else
				ra(&stacks);
			i++;
		}
		while (stacks.b_size > 0)
			pa(&stacks);
		curr_bit++;
	}
}
