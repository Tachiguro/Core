/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:47:12 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/08 22:35:22 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	calculate_chunk_size(int elements)
{
	if (elements <= 100)
		return (17);
	else
		return (50);
}

static int	create_chunks(t_stack *s_a, int chunk, int chnuk_size)
{
	int	elements;

	elements = s_a->len - 3;
	while (elements > chnuk_size)
	{
		elements -= chnuk_size;
		chunk++;
	}
	while (elements > 3)
	{
		elements /= 2;
		chunk++;
	}
	if (elements > 0)
		chunk++;
	s_a->chunks_len = chunk + 1;
	s_a->chunks = (int *)malloc(sizeof(int) * (chunk + 1));
	if (!s_a->chunks)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (chunk);
}

static void	set_chunks(t_stack *s_a, int chnuk_size)
{
	int	chunk;
	int	elements;
	int	remainder;

	elements = s_a->len - 3;
	chunk = -1;
	chunk = create_chunks(s_a, chunk, chnuk_size);
	while (elements > chnuk_size)
	{
		elements -= chnuk_size;
		s_a->chunks[chunk] = chnuk_size;
		chunk--;
	}
	while (elements > 3)
	{
		remainder = elements % 2;
		elements /= 2;
		s_a->chunks[chunk] = elements + remainder;
		remainder = 0;
		chunk--;
	}
	if (elements > 0 && chunk != 0)
		s_a->chunks[chunk + 1] += elements;
	else
		s_a->chunks[chunk] = elements;
}

static	void	choose_sort(t_stack *s_a, t_stack *s_b)
{
	if (s_a->top == 1)
		ra(s_a);
	else if (s_a->top == 2)
		sort_three(s_a);
	else
	{
		s_b->array = (int *)malloc(sizeof(int) * s_a->len);
		if (!s_b->array)
			exit(1);
		set_chunks(s_a, calculate_chunk_size(s_a->len));
		sort(s_a, s_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	s_a;
	t_stack	s_b;
	char	*joined_argv;

	joined_argv = NULL;
	init_stacks(&s_a, &s_b);
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	else if (argc == 2)
		create_s_a(argv[1], &s_a);
	else
	{
		joined_argv = join_args(argv);
		create_s_a(joined_argv, &s_a);
		free(joined_argv);
	}
	if (!s_a_sorted(&s_a))
		choose_sort(&s_a, &s_b);
	free_stack(&s_a);
	free_stack(&s_b);
	return (0);
}
