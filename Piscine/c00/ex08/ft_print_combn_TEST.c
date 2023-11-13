/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 03:09:01 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/07 14:34:03 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ini_arrs(int numbs[9], int max_numbs[9], int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		numbs[i] = i;
		max_numbs[i] = (10 - n) + i;
		i++;
	}
}

// void	print_numbs(int numbs[9], int max_numbs[9])
// {
// 	int i;
// 	char c;

// 	i = 0;
// 	while(numbs[0] != max_numbs[0])
// 	{
// 		c = numbs[i] + 48;
// 		if ((numbs[i] + 48) <= '9')
// 			write(1, "0", 1);
// 		write(1, &c, 1);
// 		i++;
// 		if (numbs[i] < max_numbs[i])
// 			write(1, ", ", 2);
// 	}
// }

// void	count_nbrs(int numbs[9], int max_numbs[9], int n)
// {
// 	int	to_change;
// 	int	i;

// 	while (numbs[0] != max_numbs[0])
// 	{
// 		to_change = n - 1;
// 		while (numbs[to_change] != max_numbs[to_change])
// 			to_change--;
// 		to_change++;
// 		i = numbs[to_change];
// 		i++;
// 		while (to_change - 1 < n)
// 			numbs[to_change] = i;
// 		print_numbs(numbs, max_numbs);
// 	}
// }

// void	ft_print_combn(int n)
// {
// 	int	numbs[9];
// 	int	max_numbs[9];

// 	if (n <= 0 || n > 9)
// 		return ;
// 	ini_arrs(numbs, max_numbs, n);
// 	print_numbs(numbs, max_numbs);
// 	count_nbrs(numbs, max_numbs, n);
// }

void	ft_print_combn(int n)
{
	int	numbs[9];
	int	max_numbs[9];
	int	i;
	char c;

	ini_arrs(numbs, max_numbs, n);
	numbs[0] = '0';
	while (numbs[0] <= max_numbs[0])
	{
		numbs[1] = numbs[0] + 1;
		i = 0;
		while (i < n)
		{
			c = numbs[i];
			write(1, &c, 1);
		}
		if (numbs[0] != max_numbs[0]
			|| numbs[1] != max_numbs[1]
			|| numbs[2] != max_numbs[2]
			|| numbs[3] != max_numbs[3]
			|| numbs[4] != max_numbs[4]
			|| numbs[5] != max_numbs[5]
			|| numbs[6] != max_numbs[6]
			|| numbs[7] != max_numbs[7]
			|| numbs[8] != max_numbs[8])
		{
			write(1, ", ", 2);
		}
		numbs[0]++;
	}
}

int	main(void)
{
	ft_print_combn(9);
	write(1, "\n", 1);
	return (0);
}