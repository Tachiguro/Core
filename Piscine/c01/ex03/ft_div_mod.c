/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:27:29 by jherzog           #+#    #+#             */
/*   Updated: 2023/01/29 00:34:25 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	i;
// 	int	j;
// 	int	div;
// 	int	mod;
// 	int	*p_div;
// 	int	*p_mod;
// 	i = 5;
// 	j = 2;
// 	p_div = &div;
// 	p_mod = &mod;
// 	ft_div_mod(i, j, p_div, p_mod);
// 	printf("div:%i, mod:%i\n", *p_div, *p_mod);
// 	return (0);
// }