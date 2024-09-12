/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:21:38 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/09 19:59:32 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_ptr(unsigned long n)
{
	int	counter;
	int	temp;

	counter = 0;
	temp = 0;
	if (n > 15)
	{
		counter = ft_print_ptr(n / 16);
		if (counter == -1)
			return (-1);
		n %= 16;
	}
	if (n > 9)
		temp = ft_print_char('a' + n - 10);
	else
		temp = ft_print_char('0' + n);
	if (temp == -1)
		return (-1);
	return (counter += temp);
}
