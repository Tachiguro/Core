/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:48:52 by jherzog           #+#    #+#             */
/*   Updated: 2023/12/16 21:26:31 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(unsigned int n)
{
	int	counter;
	int	temp;

	counter = 0;
	temp = 0;
	if (n > 9)
	{
		counter += ft_print_uint(n / 10);
		counter += ft_print_uint(n % 10);
	}
	else
	{
		temp = ft_print_char('0' + n);
		if (temp == -1)
			return (-1);
		counter += temp;
	}
	return (counter);
}
