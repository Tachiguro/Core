/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:16:40 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/06 23:24:33 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *create_fake_stack(t_stack *s)
{
	t_stack	*fake;

	fake = (t_stack *)malloc(sizeof(t_stack));
	if (!fake)
		exit(-1);
	fake->array = (int *)malloc(sizeof(int) * s->len);
	fake->chunks = (int *)malloc(sizeof(int) * s->chunks_len);
	fake->chunks_len = 0;
	fake->top = -1;
	fake->len = 0;
	fake->max_chunk = 0;
	fake->max = INT_MIN;
	return (fake);
}

void	fill_stacks(t_stack *s, t_stack *fake_s)
{
	int	i;

	i = 0;
	if (s->top > 0)
		while (i <= s->top)
		{
			fake_s->array[i] = s->array[i];
			i++;
		}
	i = 0;
	if (s->chunks_len > 0)
		while (i < s->chunks_len)
		{
			fake_s->chunks[i] = s->chunks[i];
			i++;
		}


	fake_s->chunks_len = s->chunks_len;
	fake_s->top = s->top;
	fake_s->len = s->len;
	fake_s->max_chunk = s->max_chunk;
	fake_s->max = s->max;
}

int find_cheapest_index(t_stack *s_a, t_stack *s_b)
{
	int min_op;
	int	index;
	int best_index;
	int op;
	int temp;
	t_stack *fake_s_a;
	t_stack *fake_s_b;

	fake_s_a = create_fake_stack(s_a);
	fake_s_b = create_fake_stack(s_a);
	min_op = INT_MAX;
	op = INT_MAX;
	best_index = -1;
	index = s_a->top;
	temp = 0;
	while (index >= 0)
	{
		fill_stacks(s_a, fake_s_a);
		fill_stacks(s_b, fake_s_b);
		temp = fake_s_a->array[index];
		op = 0;
		if (rrotate_to_temp(fake_s_a, temp) == 1)
		{
			while (fake_s_a->array[fake_s_a->top] != temp)
			{
				fake_rra(fake_s_a);
				op++;
			}
		}
		else
		{
			while (fake_s_a->array[fake_s_a->top] != temp)
			{
				fake_ra(fake_s_a);
				op++;
			}
		}
		while (1)
		{
			if (fake_s_a->array[fake_s_a->top] <= fake_s_a->max_chunk)
				break;
			else if (fake_s_b->top > 0 && fake_s_b->array[fake_s_b->top] < fake_s_b->array[0]
					 && rrotate_to_target(s_a, s_a->max_chunk) == 1 && fake_s_b)
			{
				fake_rrr(fake_s_a, fake_s_b);
				op++;
			}
			else if (rrotate_to_target(fake_s_a, s_a->max_chunk) == 1)
			{
				fake_rra(fake_s_a);
				op++;
			}
			else if (fake_s_b->top > 0 && fake_s_b->array[fake_s_b->top] < fake_s_b->array[0])
			{
				fake_rr(fake_s_a, fake_s_b);
				op++;
			}
			else if (fake_s_b->top > 0 && fake_s_a->array[s_a->top - 1] <= fake_s_a->max_chunk
					&& fake_s_b->array[fake_s_b->top] < fake_s_b->array[fake_s_b->top - 1])
			{
				fake_ss(fake_s_a, fake_s_b);
				op++;
			}
			else
			{
				fake_ra(fake_s_a);
				op++;
			}
		}
		if (op < min_op)
		{
			min_op = op;
			best_index = index;
		}
		index--;
	}
	if (fake_s_a)
	{
		if (fake_s_a->array)
			free(fake_s_a->array);
		if (fake_s_a->chunks)
			free (fake_s_a->chunks);
		free(fake_s_a);
		fake_s_a = NULL;
	}
	if (fake_s_b)
	{
		if (fake_s_b->array)
			free(fake_s_b->array);
		if (fake_s_b->chunks)
			free (fake_s_b->chunks);
		free(fake_s_b);
		fake_s_b = NULL;
		// test
	}
	return (best_index);
}

int	push_index_to_b(int index, t_stack *s_a, t_stack *s_b)
{
	if (rrotate_to_target(s_a, index) == 1)
		while (s_a->array[s_a->top] != index)
			rra(s_a);
	else if (s_a->array[s_a->top] != index)
		while (s_a->array[s_a->top] != index)
			ra(s_a);
	if (s_a->array[s_a->top] <= s_a->max_chunk)
	{
		pb(s_a, s_b);
		return (1);
	}
	else if ((s_b->array[s_b->top] < s_b->array[0]
			&& s_b->top > 0) && rrotate_to_target(s_a, s_a->max_chunk) == 1)
		rrr(s_a, s_b);
	else if (rrotate_to_target(s_a, s_a->max_chunk) == 1)
		rra(s_a);
	else if (s_b->array[s_b->top] < s_b->array[0] && s_b->top > 0)
		rr(s_a, s_b);
	else if (s_a->array[s_a->top - 1] <= s_a->max_chunk
			&& s_b->array[s_b->top] < s_b->array[s_b->top - 1]  && s_b->top > 0)
		ss(s_a, s_b);
	else
		ra(s_a);
	return (0);
}

void	push_to_b(int chunk, t_stack *s_a, t_stack *s_b)
{
	int	i;

	i = 0;
	s_a->max_chunk = find_max_chunk(s_a, chunk);
	while (chunk >= 0)
	{
		i += push_index_to_b(s_a->array[find_cheapest_index(s_a, s_b)], s_a, s_b);
		if (s_a->chunks[chunk] <= i)
		{
			i = 0;
			chunk--;
			s_a->max_chunk = find_max_chunk(s_a, chunk);
		}
	}
}

void	sort(t_stack *s_a, t_stack *s_b)
{
	int	chunk;
	int	rotations;

	rotations = 0;
	push_to_b(s_a->chunks_len - 1, s_a, s_b);
	if (!s_a_sorted(s_a))
		sort_three(s_a);
	chunk = 0;
	while (s_a->chunks[chunk] > 0)
	{
		if (s_b->array[s_b->top] == s_b->max && s_a->chunks[chunk] > 0)
		{
			if (rotate_to_top(s_b, s_b->max) == 1)
			{
				while (s_b->array[s_b->top] != s_b->max)
					rb(s_b);
				pb(s_a, s_b);
			}
			else
			{
				while (s_b->array[0] != s_b->min)
					rrb(s_b);
				pb(s_a, s_b);
			}

		}
		else
		{
			if (rotate_between(s_b, s_a->array[s_a->top]) == 1)
			{
				while (!(s_a->array[s_a->top] > s_b->array[s_b->top] &&
						s_a->array[s_a->top] < s_b->array[0]))
					rb(s_b);
				pb(s_a, s_b);
			}
			else
			{
				while (!(s_a->array[s_a->top] > s_b->array[s_b->top] &&
						s_a->array[s_a->top] < s_b->array[0]))
					rrb(s_b);
				pb(s_a, s_b);
			}
		}
	}
	if (rotate_to_top(s_b, s_b->max) == 1)
		while (s_b->array[s_b->top] != s_b->max)
			rb(s_b);
	else
		while (s_b->array[s_b->top] != s_b->max)
			rrb(s_b);
	while (s_b->top >= 0)
		pa(s_a, s_b);
}
