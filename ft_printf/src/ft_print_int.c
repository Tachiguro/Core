/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:44:14 by jherzog           #+#    #+#             */
/*   Updated: 2023/09/22 17:07:21 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	int				counter;
	unsigned int	u_int;

	counter = 0;
	if (n == INT_MIN)
		return (ft_print_str("-2147483648"));
	if (n < 0)
	{
		u_int = -n;
		counter += ft_print_char('-');
	}
	else
		u_int = n;
	if (u_int > 9)
		counter += ft_print_int(u_int / 10);
	counter += ft_print_char((u_int % 10) + '0');
	return (counter);
}
