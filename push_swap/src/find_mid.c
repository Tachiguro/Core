/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:45:26 by jherzog           #+#    #+#             */
/*   Updated: 2024/08/15 00:24:44 by jherzog          ###   ########.fr       */
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

int find_mid(int *array, int begin, int end)
{
	int	*arr;
	int	count;
	int	i;
	int	mid;

	count = end - begin;
	i = 0;
	arr = (int *)malloc(count * sizeof(int));
	if (!arr)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (begin <= end)
	{
		arr[i] = array[begin];
		i++;
		begin++;
	}
	bubble_sort(arr, count);
	mid = arr[count / 2 - 1];
	free(arr);
	return (mid);
}
