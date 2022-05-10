/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:26:12 by jherzog           #+#    #+#             */
/*   Updated: 2022/05/10 15:13:10 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_prit_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

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

int	ft_print_hex(va_list args)
{
	int		n;
	int		hex_len;
	char	*int_as_hex;
	int		j;

	n = va_arg(args, int);
	j = 0;
	int_as_hex = ft_itoh(n);
	hex_len = ft_strlen(int_as_hex);
	while (int_as_hex[j] != '\0')
	{
		if (to_upper)
			int_as_hex[j] = ft_toupper(int_as_hex[j]);
		write(1, &int_as_hex, hex_len);
		j++;
	}
	return (hex_len);
}

int	ft_print_pointer(va_list args)
{
	int					c_letters;
	unsigned long long	pval;

	c_letters = 0;
	pval = va_arg(args, unsigned long long);
	c_letters += write(1, "0x", 2);
	c_letters += write(1, ft_ulltoh(pval), 18);
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
