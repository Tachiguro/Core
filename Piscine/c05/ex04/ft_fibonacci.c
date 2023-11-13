/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:10:31 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/08 16:05:52 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1 || index == 2)
		return (1);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
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
// 	i = ft_fibonacci(nb);
// 	printf("i:%i\n", i);
// 	return (0);
// }