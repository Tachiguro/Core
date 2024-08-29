/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:16:40 by jherzog           #+#    #+#             */
/*   Updated: 2024/08/30 00:49:02 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *create_fake_stack(t_stack *original)
{
	t_stack	*fake;
	int		i;

	i = -1;
	fake = (t_stack *)malloc(sizeof(t_stack));
	if (!fake)
		exit(1);
	fake->len = original->len;
	fake->top = original->top;
	fake->chunks_len = original->chunks_len;
	fake->max_chunk = original->max_chunk;
	fake->max = original->max;
	fake->array = (int *)malloc(sizeof(int) * fake->len);
	if (!fake->array)
		exit(1);
	while (++i <= fake->top)
		fake->array[i] = original->array[i];
	fake->chunks = (int *)malloc(sizeof(int) * fake->chunks_len);
	if (!fake->chunks)
		exit(1);
	i = -1;
	while (++i < fake->chunks_len)
		fake->chunks[i] = original->chunks[i];
	return (fake);
}

void free_fake_stack(t_stack *fake)
{
	if (fake)
	{
		if (fake->array)
			free(fake->array);
		if (fake->chunks)
			free(fake->chunks);
		free(fake);
	}
}

int find_cheapest_index(t_stack *s_a, t_stack *s_b)
{
	int min_op;
	int	index;
	int best_index;
	int op;
	t_stack *fake_s_a;
	t_stack *fake_s_b;

	fake_s_a = NULL;
	fake_s_b = NULL;
	min_op = INT_MAX;
	op = INT_MAX;
	best_index = -1;
	index = s_a->top;
	while (index >= 0)
	{

		fake_s_a = create_fake_stack(s_a);
		if (s_b->len > 0)
			fake_s_b = create_fake_stack(s_b);
		op = 0;
		if (rrotate_to_target(fake_s_a, fake_s_a->array[index]) == 1)
		{
			TODO:FUUUUCK!!!
			while (fake_s_a->array[fake_s_a->top] != fake_s_a->array[index])
			{
				fake_rra(fake_s_a);
				op++;
			}
		}
		else
		{
			while (fake_s_a->array[fake_s_a->top] != fake_s_a->array[index])
			{
				fake_ra(fake_s_a);
				op++;
			}
		}
		while (1)
		{
			if (fake_s_a->array[fake_s_a->top] <= fake_s_a->max_chunk)
				break;
			// else if ((fake_s_b->array[fake_s_b->top] < fake_s_b->array[0]
			// 		&& fake_s_b->top > 0) && rrotate_to_target(s_a, s_a->max_chunk) == 1 && fake_s_b)
			// {
			// 	fake_rrr(fake_s_a, s_b);
			// 	op++;
			// }
			else if (rrotate_to_target(fake_s_a, s_a->max_chunk) == 1)
			{
				fake_rra(fake_s_a);
				op++;
			}
			// else if (fake_s_b->array[fake_s_b->top] < fake_s_b->array[0] && fake_s_b->top > 0)
			// {
			// 	fake_rr(fake_s_a, fake_s_b);
			// 	op++;
			// }
			else if (fake_s_a->array[s_a->top - 1] <= fake_s_a->max_chunk
					&& fake_s_b->array[fake_s_b->top] < fake_s_b->array[fake_s_b->top - 1]  && fake_s_b->top > 0)
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
		free_fake_stack(fake_s_a);
		if (fake_s_b)
			free_fake_stack(fake_s_b);
		if (op < min_op)
		{
			min_op = op;
			best_index = index;
		}
		index--;
	}
	return (best_index);
}

int	push_index_to_b(int index, t_stack *s_a, t_stack *s_b)
{
	if (rrotate_to_target(s_a, s_a->array[index]) == 1)
		while (s_a->array[s_a->top] == s_a->array[index])
			rra(s_a);
	else if (s_a->array[s_a->top] != s_a->array[index])
		while (s_a->array[s_a->top] == s_a->array[index])
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
		i += push_index_to_b(find_cheapest_index(s_a, s_b), s_a, s_b);
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
			pa(s_a, s_b);
			s_a->chunks[chunk]--;
			while (rotations > 0 && s_b->top > 0 && rrotate_to_max(s_b, s_b->max) == 1 && s_a->chunks_len -1 != chunk)
			{
				if (s_b->array[s_b->top] == s_b->max)
				{
					pa(s_a, s_b);
					s_a->chunks[chunk]--;
				}
				rrb(s_b);
				rotations--;
			}
			while (rotations < 0 && s_b->top > 0 && s_a->chunks_len -1 != chunk)
			{
				if (s_b->array[s_b->top] == s_b->max)
				{
					pa(s_a, s_b);
					s_a->chunks[chunk]--;
				}
				rb(s_b);
				rotations++;
			}
		}
		else if (rrotate_to_max(s_b, s_b->max) == 1)
		{
			rrb(s_b);
			rotations--;
		}
		else
		{
			rb(s_b);
			rotations++;
		}
		if (s_b->top == -1)
			break ;
		if (s_a->chunks[chunk] <=  0)
			chunk++;
	}
}
