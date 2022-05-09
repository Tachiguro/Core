/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:51:20 by jherzog           #+#    #+#             */
/*   Updated: 2022/05/09 13:30:14 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft\libft.h"

int		ft_printf(const char *format, ...)
{
	int i = 0;

	va_list args;
	va_start(args, format);

	while(format[i] != '\0')
	{
		if(format[i - 1] == '%' &&
			(format[i] == 'c' || format[i] == 's' || format[i] == 'p' ||
			format[i] == 'd' || format[i] == 'i' || format[i] == 'u' ||
			format[i] == 'x' || format[i] == 'X' || format[i] == '%'))
		{
			i++;
		}
		if(format[i] == '%' && format[i + 1] == 'c')
		{
			char c = va_arg(args, int);
			write(1, &c, 1);
		}
		else if(format[i] == '%' && format[i + 1] == 's')
		{
			char *s = va_arg(args, char *);
			int str_len = func_strlen(s);
			write(1, s, str_len);
		}
		else if(format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
        {
            int i = va_arg(args, int);
            char *inumb = func_itoa(i);
            int numlen = func_strlen(inumb);
            write(1, inumb, numlen);
        }
        else if(format[i] == '%' && format[i + 1] == 'x')
        {
            int i = va_arg(args, int);
            char *inumb = func_itoh(i);
            int numlen = func_strlen(inumb);
            write(1, inumb, numlen);
        }
        else if(format[i] == '%' && format[i + 1] == 'X')
        {
            int i = va_arg(args, int);
            int j = 0;
            char *inumb = func_itoh(i);
            char upperinumb;
            int numlen = func_strlen(inumb);
            while(inumb[j] != '\0')
            {
                upperinumb = to_upper(inumb[j]);
                write(1, &upperinumb, 1);
                j++;
            }
        }
        else if(format[i] == '%' && format[i + 1] == 'p')
        {
            unsigned long long pval;
            pval = va_arg(args,  unsigned long long);
            write(1,  "0x", 2);

            write(1, func_ulltoh(pval), 12);
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
}
