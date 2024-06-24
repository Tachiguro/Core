/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:47:12 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/24 20:40:55 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	set_chunks(t_stack *s_a)
{
	int	chunk;
	int	top;

	top = s_a->top;
	chunk = -1;
	while (++chunk < top)
		top /= 2;
	s_a->chunks_len = chunk;
	s_a->chunks = (int *)malloc(sizeof(int) * chunk + 1);
	chunk = -1;
	top = s_a->top;
	while (++chunk <= s_a->chunks_len)
	{
		top /= 2;
		s_a->chunks[chunk] = top;
	}
	s_a->chunks[chunk + 1] = -1;
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
		s_b.len = s_b.top;
		s_b.array = (int *)malloc(sizeof(int) * s_a.top);
		if (!s_b.array)
			exit(1);
		set_chunks(&s_a);
		if (!s_b.array)
			exit(1);
		sort(&s_a, &s_b);
		free(s_b.array);
		free(s_a.array);
	}
	return (0);
}
