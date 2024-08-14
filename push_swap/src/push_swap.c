/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:47:12 by jherzog           #+#    #+#             */
/*   Updated: 2024/08/14 22:53:20 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	create_chunks(t_stack *s_a)
{
	int	chunk;
	int	elements;

	elements = s_a->len;
	chunk = -1;
	while (elements > 2)
	{
		elements /= 2;
		chunk++;
	}
	s_a->chunks_len = chunk + 1;
	s_a->chunks = (int *)malloc(sizeof(int) * (chunk + 1));
	if (!s_a->chunks)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (chunk);
}

static void	set_chunks(t_stack *s_a)
{
	int	chunk;
	int	elements;
	int	elements_count;

	elements_count = 0;
	elements = s_a->len;
	chunk = create_chunks(s_a);
	while (chunk >= 0 && (elements / 2 != 0))
	{
		elements /= 2;
		elements_count += elements;
		s_a->chunks[chunk] = elements;
		chunk--;
	}
	if ((s_a->len - 2) > elements_count)
		s_a->chunk_remainer += s_a->len - elements_count - 2;
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
			ra(&s_a);
		else
		{
			s_b.len = s_b.top;
			s_b.array = (int *)malloc(sizeof(int) * s_a.top);
			if (!s_b.array)
				exit(1);
			set_chunks(&s_a);
			sort(&s_a, &s_b);
		}
	}
	if(s_a_sorted(&s_a))
		write(1,"OK!\n", 4);
	else
		write(1, "KO!\n", 4);
	return (0);
}
