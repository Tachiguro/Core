/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:37:06 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/09 01:33:53 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	i = 1;
	while (++i < nb && i <= 46340)
	{
		if (nb == (i * i))
			return (i);
	}
	return (0);
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