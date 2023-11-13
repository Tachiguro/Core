/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:21:11 by jherzog           #+#    #+#             */
/*   Updated: 2023/01/29 00:26:41 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	*p_i;
// 	int	*p_j;
// 	int	i;
// 	int	j;
// 	i = 7;
// 	j = 5;
// 	p_i = &i;
// 	p_j = &j;
// 	printf("Before swap:");
// 	printf("%i", *p_i);
// 	printf("%i", *p_j);
// 	ft_swap(p_i, p_j);
// 	printf("\nAfter swap:");
// 	printf("%i", *p_i);
// 	printf("%i\n", *p_j);
// 	return (0);
// }