/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:37:08 by jherzog           #+#    #+#             */
/*   Updated: 2023/09/22 17:00:27 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, int toupper)
{
	int	counter;

	counter = 0;
	if (n > 15)
	{
		counter += ft_print_hex(n / 16, toupper);
		counter += ft_print_hex(n % 16, toupper);
	}
	else if (n > 9)
	{
		if (toupper)
			counter += ft_print_char('A' + n - 10);
		else
			counter += ft_print_char('a' + n - 10);
	}
	else
		counter += ft_print_char('0' + n);
	return (counter);
}
