/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 04:18:31 by jherzog           #+#    #+#             */
/*   Updated: 2023/01/29 23:37:14 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	sorted;

	sorted = 0;
	while (sorted < size -1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		sorted++;
	}
}

// #include <stdio.h>
// int	main(void)
// {
// 	int i = 0;
// 	int len = 3;
// 	int arr0[] = {3, 2, 1};
// 	printf("Test1: before sort	:");
// 	while (i < len)
// 	{
// 		printf("%d ", arr0[i]);
// 		++i;
// 	}
// 	printf("\nTest1: after sort	:");
// 	ft_sort_int_tab(arr0, len);
// 	i = 0;
// 	while (i < len)
// 	{
// 		printf("%d ", arr0[i]);
// 		++i;
// 	}
// 	printf("\n");
// 	len = 6;
// 	int arr1[] = {5,3,6,4,2,1};
// 	printf("Test2: before sort	:");
// 	i = 0;
// 	while (i < len)
// 	{
// 		printf("%d ", arr1[i]);
// 		++i;
// 	}
// 	printf("\nTest2: after sort	:");
// 	ft_sort_int_tab(arr1, len);
// 	i = 0;
// 	while (i < len)
// 	{
// 		printf("%d ", arr1[i]);
// 		++i;
// 	}
// 	printf("\n");
// 	return (0);
// }