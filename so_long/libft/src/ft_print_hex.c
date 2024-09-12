/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:37:08 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/09 19:59:22 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hex(unsigned int n, char begin)
{
	int	counter;
	int	temp;

	counter = 0;
	temp = 0;
	if (n > 15)
	{
		counter = ft_print_hex(n / 16, begin);
		n %= 16;
	}
	if (counter == -1)
		return (-1);
	if (n > 9)
		temp = ft_print_char(begin + n - 10);
	else
		temp = ft_print_char('0' + n);
	if (temp == -1)
		return (-1);
	return (counter + temp);
}
