/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:44:14 by jherzog           #+#    #+#             */
/*   Updated: 2023/12/16 21:24:50 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	int				counter;
	unsigned int	u_int;
	int				temp;

	counter = 0;
	temp = 0;
	if (n == INT_MIN)
		return (ft_print_str("-2147483648"));
	if (n < 0)
	{
		u_int = -n;
		counter = ft_print_char('-');
		if (counter == -1)
			return (-1);
	}
	else
		u_int = n;
	if (u_int > 9)
		counter += ft_print_int(u_int / 10);
	temp = ft_print_char((u_int % 10) + '0');
	if (temp == -1)
		return (-1);
	counter += temp;
	return (counter);
}
