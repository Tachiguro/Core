/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:30:30 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/09 21:34:49 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	base_nb;

	base_nb = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (--power > 0)
		nb *= base_nb;
	return (nb);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// int	main(int argc, char **argv)
// {
// 	int		msec = 0;
// 	int		trigger = 10;
// 	int		iterations = 0;
// 	clock_t	before = clock();
// 	int		i;
// 	int		nb;
// 	if (argc < 2)
// 	{
// 		printf("Need a argument!\n");
// 		return (1);
// 	}
// 	nb = atoi(argv[1]);
// 	printf("nb:%i\n", nb);
// 	do {
// 		i = ft_sqrt(nb);
// 		clock_t difference = clock() - before;
// 		msec = difference * 1000 / CLOCKS_PER_SEC;
// 		iterations++;
// 	} while ( msec < trigger );
// 	printf("i:%i\n", i);
// 	printf("Time taken %d seconds %d milliseconds (%d iterations)\n",
// 	msec/1000, msec%1000, iterations);
// 	return (0);
// }