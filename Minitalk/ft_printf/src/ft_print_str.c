/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 23:38:48 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/09 19:59:35 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_str(char *str)
{
	int	counter;
	int	len;

	counter = 0;
	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	counter = write(1, str, len);
	if (counter == -1)
		return (-1);
	return (counter);
}
