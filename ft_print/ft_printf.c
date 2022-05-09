/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:51:20 by jherzog           #+#    #+#             */
/*   Updated: 2022/05/09 15:11:10 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

int	ft_prit_char(va_list args)
{
	char				c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(va_list args)
{
	char *s;
	int str_len;

	s = va_arg(args, char *);
	str_len = ft_strlen(s);
	write(1, s, str_len);
	return (str_len);
}

int	ft_print_int(va_list args)
{
	int 	n;
	int 	num_len;
	char	*int_as_string;

	n = va_arg(args, int);
	int_as_string = ft_itoa(i);
	num_len = ft_strlen(int_as_string);
	write(1, int_as_string, num_len);
	return (num_len);
}

int	ft_print_hex(va_list args, int to_upper)
{
	int 	n;
	int 	hex_len;
	char	*int_as_hex;
	int 	j;

	n = va_arg(args, int);
	j = 0;
	int_as_hex = ft_itoh(i);
	hex_len = ft_strlen(int_as_hex);
	if (to_upper)
	{
		while (int_as_hex[j] != '\0')
		{
			int_as_hex[j] = ft_toupper(int_as_hex[j]);
			write(1, &int_as_hex, hex_len);
			j++;
		}
	}
	return (hex_len);
}

int	ft_print_pointer(va_list args)
{
	
	int					c_letters;
	unsigned long long	pval;

	pval = va_arg(args, unsigned long long);
	c_letters += write(1, "0x", 2);
	c_letters += write(1, ft_ulltoh(pval), 12);
	return (c_letters);
}

int	ft_check_format(const char *format, int i, va_list args)
{
	int					c_letters;

	c_letters = 0;
	if (format[i] == '%' && format[i + 1] == 'c')
		c_letters += ft_prit_char(args);
	else if (format[i] == '%' && format[i + 1] == 's')
		c_letters +=  ft_print_string(args);
	else if (format[i] == '%' && (format[i + 1] == 'd'
			|| format[i + 1] == 'i'))
		c_letters +=  ft_print_int(args);
	else if (format[i] == '%' && (
				format[i + 1] == 'x' || format[i + 1] == 'X'))
	{
		if (format[i + 1] == 'X')
			c_letters +=  ft_print_hex(args, 1);
		else
			c_letters +=  ft_print_hex(args, 0);
	}
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
	va_list				args;
	int					i;
	int					c_letters;

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
		c_letters += ft_check_format(format, i, args);
		i++;
	}
	va_end(args);
	return (c_letters);
}
