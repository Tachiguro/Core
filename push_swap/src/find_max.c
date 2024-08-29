/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:45:26 by jherzog           #+#    #+#             */
/*   Updated: 2024/08/18 23:16:32 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		swapped = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}

int	find_max_chunk(t_stack *s_a, int chunk)
{
	int *arr;
	int mid;
	int	i;

	i = 0;
	arr = (int *)malloc((s_a->top + 1) * sizeof(int));
	if (!arr)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (i < s_a->top + 1)
	{
		arr[i] = s_a->array[i];
		i++;
	}
	bubble_sort(arr, s_a->top + 1);
	mid = arr[s_a->chunks[chunk] - 1];
	free(arr);
	return (mid);
}
