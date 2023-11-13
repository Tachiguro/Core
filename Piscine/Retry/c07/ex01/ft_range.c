/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 03:07:42 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/14 02:31:56 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (0);
	arr = (int *)malloc((max - min) * sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	*arr;
// 	int	min;
// 	int	max;
// 	int	i;

// 	min = 10;
// 	max = 10;
// 	i = 0;
// 	arr = ft_range(min, max);
// 	while (i < max - min)
// 	{
// 		printf("arr[%i]:%i\n", i, arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	return (0);
// }