/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:21:38 by jherzog           #+#    #+#             */
/*   Updated: 2023/09/22 17:00:33 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long n)
{
	int	counter;

	counter = 0;
	if (n > 15)
	{
		counter += ft_print_ptr(n / 16);
		counter += ft_print_ptr(n % 16);
	}
	else if (n > 9)
		counter += ft_print_char('a' + n - 10);
	else
		counter += ft_print_char('0' + n);
	return (counter);
}
