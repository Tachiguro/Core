/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:51:20 by jherzog           #+#    #+#             */
/*   Updated: 2022/05/10 16:31:23 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_check_format(const char *format, int i, va_list args, int c_letters)
{
	char	c;

	if (format[i] == '%' && format[i + 1] == 'c')
	{
		c = va_arg(args, int);
		c_letters += write(1, &c, 1);
	}
	else if (format[i] == '%' && format[i + 1] == 's')
		c_letters += ft_print_string(args);
	else if (format[i] == '%' && (format[i + 1] == 'd'
			|| format[i + 1] == 'i'))
		c_letters += ft_print_int(args);
	else if (format[i] == '%' && format[i + 1] == 'x')
		c_letters += ft_print_hex(args, 0);
	else if (format[i] == '%' && format[i + 1] == 'X')
		c_letters += ft_print_hex(args, 1);
	else if (format[i] == '%' && format[i + 1] == 'u')
		c_letters += ft_print_u(args);
	else if (format[i] == '%' && format[i + 1] == 'p')
		c_letters += ft_print_pointer(args);
	else if (format[i] == '%' && format[i + 1] == '%')
		c_letters += write(1, "%", 1);
	else
		c_letters += write(1, &format[i], 1);
	return (c_letters);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		c_letters;

	i = 0;
	c_letters = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i - 1] == '%'
			&& (format[i] == 'c' || format[i] == 's' || format[i] == 'p'
				|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
				|| format[i] == 'x' || format[i] == 'X' || format[i] == '%'))
		{
			i++;
		}
		c_letters += ft_check_format(format, i, args, c_letters);
		i++;
	}
	va_end(args);
	return (c_letters);
}
