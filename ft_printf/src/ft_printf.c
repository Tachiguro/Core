/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:59:55 by jherzog           #+#    #+#             */
/*   Updated: 2023/09/22 17:00:43 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(const char *f, int i, va_list args)
{
	int	counter;

	counter = 0;
	if (f[i] == '%')
		counter += ft_print_char('%');
	else if (f[i] == 'c')
		counter += ft_print_char(va_arg(args, int));
	else if (f[i] == 's')
		counter += ft_print_str(va_arg(args, char *));
	else if (f[i] == 'd' || f[i] == 'i')
		counter += ft_print_int(va_arg(args, int));
	else if (f[i] == 'u')
		counter += ft_print_uint(va_arg(args, unsigned int));
	else if (f[i] == 'x')
		counter += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (f[i] == 'X')
		counter += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (f[i] == 'p')
	{
		counter += ft_print_str("0x");
		counter += ft_print_ptr(va_arg(args, unsigned long));
	}
	return (counter);
}

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	if (f == NULL)
		return (0);
	va_start(args, f);
	while (f[i])
	{
		if (f[i] == '%')
			counter += ft_check_format(f, ++i, args);
		else
			counter += ft_print_char(f[i]);
		i++;
	}
	va_end(args);
	return (counter);
}
