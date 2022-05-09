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

int	ft_printf(const char *format, ...)
{
	va_list				args;
	int					i;
	int					c_letters;
	char				c;
	char				*s;
	int					n;
	int					j;
	unsigned long long	pval;
	int					str_len;
	char				*inumb;
	int					numlen;
	char				upperinumb;

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
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = va_arg(args, int);
			write(1, &c, 1);
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			*s = va_arg(args, char *);
			str_len = ft_strlen(s);
			write(1, s, str_len);
		}
		else if (format[i] == '%' && (format[i + 1] == 'd'
				|| format[i + 1] == 'i'))
		{
			n = va_arg(args, int);
			inumb = ft_itoa(i);
			numlen = ft_strlen(inumb);
			write(1, inumb, numlen);
		}
		else if (format[i] == '%' && format[i + 1] == 'x')
		{
			n = va_arg(args, int);
			inumb = ft_itoh(i);
			numlen = ft_strlen(inumb);
			write(1, inumb, numlen);
		}
		else if (format[i] == '%' && format[i + 1] == 'X')
		{
			n = va_arg(args, int);
			j = 0;
			inumb = ft_itoh(i);
			numlen = ft_strlen(inumb);
			while (inumb[j] != '\0')
			{
				upperinumb = ft_toupper(inumb[j]);
				write(1, &upperinumb, numlen);
				j++;
			}
		}
		else if (format[i] == '%' && format[i + 1] == 'p')
		{
			pval = va_arg(args, unsigned long long);
			write(1, "0x", 2);
			write(1, ft_ulltoh(pval), 12);
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, "%", 1);
		}
		else
		{
			write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (c_letters);
}
