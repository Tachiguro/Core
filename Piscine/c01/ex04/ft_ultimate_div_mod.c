/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:35:07 by jherzog           #+#    #+#             */
/*   Updated: 2023/01/29 01:41:25 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	a = 5;
// 	int	b = 2;
// 	printf("a:%i, a:%i\n", a, b);
// 	ft_ultimate_div_mod(&a, &b);
// 	printf("a:%i, a:%i\n", a, b);
// 	return (0);
// }