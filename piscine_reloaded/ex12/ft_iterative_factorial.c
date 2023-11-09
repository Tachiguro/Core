/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:46:32 by jherzog           #+#    #+#             */
/*   Updated: 2023/11/09 17:19:24 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	sum;

	sum = nb;
	if (nb > 12)
	{
		return (0);
	}
	while (nb > 0)
	{
		sum = sum * nb;
		nb--;
	}
	return (sum);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	i;

// 	i = 20;
// 	while (i > 0)
// 	{
// 	printf("factorial: %d i: %d\n", ft_iterative_factorial(i), i);
// 	i--;
// 	}

// 	return (0);
// }
