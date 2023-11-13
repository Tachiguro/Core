/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 03:03:27 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/14 02:33:26 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = malloc((max - min) * sizeof(int));
	if (!range)
		return (0);
	i = 0;
	while (min < max)
	{
		range[0][i] = min;
		min++;
		i++;
	}
	return (size);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	*arr;
// 	int	size;
// 	int	min;
// 	int	max;
// 	int	i;

// 	min = 9;
// 	max = 10;
// 	i = 0;
// 	size = ft_ultimate_range(&arr, min, max);
// 	printf("size:%i\n", size);
// 	while (i < max - min)
// 	{
// 		printf("arr:%i\n", arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	return (0);
// }