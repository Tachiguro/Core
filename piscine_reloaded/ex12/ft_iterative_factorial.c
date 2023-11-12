/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:46:32 by jherzog           #+#    #+#             */
/*   Updated: 2023/11/12 14:43:23 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	sum;

	sum = 1;
	if (nb == 0)
		return (1);
	if (nb > 12 || nb < 0)
		return (0);
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
// 	int	i[] = {0,1,2,5,7,10,11,12,66};
// 	int j = 0;

// 	while (j < 9)
// 	{
// 		printf("%d: f: %d i: %d\n", j, ft_iterative_factorial(i[j]), i[j]);
// 		j++;
// 	}

// 	return (0);
// }
