/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 02:01:32 by jherzog           #+#    #+#             */
/*   Updated: 2023/01/30 08:00:40 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	temp;

	start = 0;
	while (size > start)
	{
		temp = tab[start];
		tab[start] = tab[size - 1];
		tab[size - 1] = temp;
		size--;
		start++;
	}
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	size = 6;
// 	int	i;
// 	int	arr[] = {1, 2, 3, 4, 5, 6};
// 	printf("Before:");
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d ", arr[i]);
// 		++i;
// 	}
// 	ft_rev_int_tab(arr, size);
// 	printf("After:");
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d ", arr[i]);
// 		++i;
// 	}

// 	printf("\n");
// 	size = 5;
// 	int	arr1[] = {1, 2, 3, 4, 5};
// 	printf("Before:");
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d ", arr1[i]);
// 		++i;
// 	}
// 	ft_rev_int_tab(arr1, size);
// 	printf("After:");
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d ", arr1[i]);
// 		++i;
// 	}
// 	printf("\n");
// }