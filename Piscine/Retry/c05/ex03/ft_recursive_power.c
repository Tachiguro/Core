/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:54:52 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/07 23:04:48 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	return (ft_recursive_power(nb, power - 1) * nb);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	i;

// 	i = 0;
// 	i = ft_recursive_power(5, 4);
// 	printf("i:%i\n", i);
// 	return (0);
// }