/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:45:26 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/24 14:55:35 by jherzog          ###   ########.fr       */
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

void	find_mid(t_stack *s_a)
{
	int	i;
	int	*arr;
	int	count;

	i = 0;
	count = s_a->top + 1;
	arr = (int *)malloc(count * sizeof(int));
	if (!arr)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (i < count)
	{
		arr[i] = s_a->array[i];
		i++;
	}
	bubble_sort(arr, count);
	if (count % 2 == 0)
		s_a->mid = arr[count / 2 - 1] + arr[count / 2] / 2;
	else
		s_a->mid = arr[(count - 1) / 2];
	free(arr);
}
