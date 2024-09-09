/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:44:14 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/09 19:59:28 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_int(int n)
{
	int	counter;
	int	temp;

	counter = 0;
	temp = 0;
	if (n == INT_MIN)
		return (ft_print_str("-2147483648"));
	if (n < 0)
	{
		n = -n;
		counter = ft_print_char('-');
		if (counter == -1)
			return (-1);
	}
	if (n > 9)
	{
		temp = ft_print_int(n / 10);
		if (temp == -1)
			return (-1);
		counter += temp;
	}
	temp = ft_print_char((n % 10) + '0');
	if (temp == -1)
		return (-1);
	return (counter + temp);
}
