/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:47:12 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/25 03:23:11 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	set_chunks(t_stack *s_a)
{
	int	chunk;
	int	element;

	element = s_a->top;
	chunk = 0;
	while (++chunk < element)
		element /= 2;
	s_a->chunks_len = chunk;
	s_a->chunks = (int *)malloc(sizeof(int) * chunk);
	if (!s_a->chunks)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	chunk = -1;
	element = s_a->top - 2;
	while (++chunk < s_a->chunks_len - 1)
	{
		if (element % 2 == 0)
		{
			element = (element / 2 )- 1;
			s_a->chunks[chunk] = element;
		}
		else
		{
			element = (element - 1) / 2;
			s_a->chunks[chunk] = element;
		}
	}
	s_a->chunks[chunk] = -1;
	return (chunk);
}

int	main(int argc, char **argv)
{
	t_stack	s_a;
	t_stack	s_b;

	init_stacks(&s_a, &s_b);
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		create_s_a(argv[1], &s_a);
	else
		create_s_a(join_args(argv), &s_a);
	if (!s_a_sorted(&s_a))
	{
		if (s_a.top == 1)
		{
			ra(&s_a);
			return (0);
		}
		s_b.len = s_b.top;
		s_b.array = (int *)malloc(sizeof(int) * s_a.top);
		if (!s_b.array)
			exit(1);
		set_chunks(&s_a);
		sort(&s_a, &s_b);
	}
	return (0);
}
