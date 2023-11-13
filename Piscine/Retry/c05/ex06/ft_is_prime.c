/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 03:02:17 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/17 00:07:04 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1 || nb % 2 == 0)
		return (0);
	else if (nb <= 3)
		return (1);
	i = 5;
	while (i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
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
// 		printf("Need an argument!\n");
// 		return (1);
// 	}
// 	nb = atoi(argv[1]);
// 	printf("nb:%i\n", nb);
// 	do {
// 		i = ft_is_prime(nb);
// 		clock_t difference = clock() - before;
// 		msec = difference * 1000 / CLOCKS_PER_SEC;
// 		iterations++;
// 	} while ( msec < trigger );
// 	printf("i:%i\n", i);
// 	printf("Time taken %d seconds %d milliseconds (%d iterations)\n",
// 	msec/1000, msec%1000, iterations);
// 	return (0);
// }