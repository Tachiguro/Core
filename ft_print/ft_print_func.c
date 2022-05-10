/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:26:12 by jherzog           #+#    #+#             */
/*   Updated: 2022/05/10 16:30:24 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_string(va_list args)
{
	char	*s;
	int		str_len;

	s = va_arg(args, char *);
	str_len = ft_strlen(s);
	write(1, s, str_len);
	return (str_len);
}

int	ft_print_int(va_list args)
{
	int		n;
	int		num_len;
	char	*int_as_string;

	n = va_arg(args, int);
	int_as_string = ft_itoa(n);
	num_len = ft_strlen(int_as_string);
	write(1, int_as_string, num_len);
	return (num_len);
}

int	ft_print_hex(va_list args, int is_upper)
{
	int		i;
	int		n;
	int		hex_len;
	char	*inumb;
	char	upperinumb;

	n = va_arg(args, int);
	inumb = ft_ultoh(n);
	i = 0;
	hex_len = 0;
	if (is_upper == 1)
	{
		while (inumb[i] != '\0')
		{
			upperinumb = ft_toupper(inumb[i]);
			hex_len += write(1, &upperinumb, 1);
			i++;
		}
	}
	else
	{
		hex_len = ft_strlen(inumb);
		write(1, inumb, hex_len);
	}
	return (hex_len);
}

int	ft_print_pointer(va_list args)
{
	int				c_letters;
	unsigned long	pval;

	c_letters = 0;
	pval = va_arg(args, unsigned long);
	c_letters += write(1, "0x", 2);
	if (pval == 0)
	{
		c_letters += write(1, "0", 1);
	}
	else
		c_letters += write(1, ft_ultoh(pval), 12);
	return (c_letters);
}

int	ft_print_u(va_list args)
{
	unsigned int	n;
	int				num_len;
	char			*int_as_string;

	num_len = 0;
	n = va_arg(args, unsigned int);
	int_as_string = ft_itoa(n);
	num_len = ft_strlen(int_as_string);
	write(1, int_as_string, num_len);
	return (num_len);
}
