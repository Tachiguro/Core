/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:20:51 by jherzog           #+#    #+#             */
/*   Updated: 2023/11/09 17:44:14 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	else if (nb < 0 || nb > 12)
		return (0);
	else
		return (nb * ft_recursive_factorial(nb -1));
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	i;

// 	i = 20;
// 	while (i >= 0)
// 	{
// 	printf("factorial: %d i: %d\n", ft_recursive_factorial(i), i);
// 	i--;
// 	}

// 	return (0);
// }
