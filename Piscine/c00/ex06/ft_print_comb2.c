/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 03:47:37 by jherzog           #+#    #+#             */
/*   Updated: 2023/01/30 23:20:15 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numbs(int numb)
{
	int f;
	int s;
	
	f = (numb / 10) + '0';
	s = (numb % 10) + '0';
	write(1, &f, 1);
	write(1, &s, 1);
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			print_numbs(first);
			write(1, " ", 1);
			print_numbs(second);
			if (first != 98 || second != 99)
				write(1, ", ", 2);
			second++;
		}
		first++;
	}
}

// int	main(void)
// {
// 	ft_print_comb2();
// 	return (0);
// }