/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:56:35 by jherzog           #+#    #+#             */
/*   Updated: 2023/01/31 15:35:51 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

#include <stdio.h>
int	main(void)
{
	int *p_int;
	int i;
	i = 10;
	p_int = &i;
	ft_ft(p_int);
	printf("%i\n", *p_int);
	return (0);
}