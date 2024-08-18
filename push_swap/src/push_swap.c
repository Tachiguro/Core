/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:47:12 by jherzog           #+#    #+#             */
/*   Updated: 2024/08/19 00:25:57 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#define MAX_CHUNK_SIZE 17

static int	create_chunks(t_stack *s_a)
{
	int	chunk;
	int	elements;

	elements = s_a->len;
	chunk = -1;
	if (elements > MAX_CHUNK_SIZE && elements != MAX_CHUNK_SIZE)
		while (elements > MAX_CHUNK_SIZE)
		{
			elements -= MAX_CHUNK_SIZE;
			chunk++;
		}
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
	int chunk;
	int elements;
	int remainder;

	elements = s_a->len;
	chunk = create_chunks(s_a);
	if (elements > MAX_CHUNK_SIZE)
		while (elements > MAX_CHUNK_SIZE)
		{
			elements -= MAX_CHUNK_SIZE;
			s_a->chunks[chunk] = MAX_CHUNK_SIZE;
			chunk--;
		}
	while (chunk >= 0 && elements > 2)
	{
		if (elements > 3)
			remainder = elements % 2;
		elements /= 2;
		s_a->chunks[chunk] = elements + remainder;
		remainder = 0;
		chunk--;
	}
	// if (chunk >= 0 && elements > 0)
	// 	s_a->chunks[chunk] = elements;
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
	{
		write(1, "KO!\n", 4);
	for (int i = s_a.top; i >= 0; i--)  // Starte bei s_a.top und zähle bis 0 herunter
	{
		printf("%d\n", s_a.array[i]);  // Gebe jedes Element auf der Konsole aus
	}
	}
	return (0);
}
