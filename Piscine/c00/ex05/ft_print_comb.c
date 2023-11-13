/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 03:10:52 by jherzog           #+#    #+#             */
/*   Updated: 2023/01/28 00:35:18 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	numbs[3];

	numbs[0] = '0';
	while (numbs[0] <= '7')
	{
		numbs[1] = numbs[0] + 1;
		while (numbs[1] <= '8')
		{
			numbs[2] = numbs[1] + 1;
			while (numbs[2] <= '9')
			{
				write(1, numbs, 1);
				write(1, numbs + 1, 1);
				write(1, numbs + 2, 1);
				if (numbs[0] != '7' || numbs[1] != '8' || numbs[2] != '9')
				{
					write(1, ", ", 2);
				}
				numbs[2]++;
			}
			numbs[1]++;
		}
		numbs[0]++;
	}
}
