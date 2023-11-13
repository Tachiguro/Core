/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:48:43 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/09 16:21:44 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	while (++i <= nb)
		result *= i;
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(int argc, char **argv)
// {
// 	int	i;
// 	int	nb;

// 	if (argc < 2)
// 	{
// 		printf("Need a argument!\n");
// 		return (1);
// 	}
// 	nb = atoi(argv[1]);
// 	printf("nb:%i\n", nb);
// 	i = ft_iterative_factorial(nb);
// 	printf("i:%i\n", i);
// 	return (0);
// }