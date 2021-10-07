/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:52:40 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/07 12:18:28 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strinigfy(long n, int l, char *number)
{
	char	neg;

	if (n < 0)
	{
		neg = '-';
		n = -n;
	}
	number[l] = '\0';
	l = l - 1;
	while (l > 0)
	{
		number[l] = (n % 10) + '0';
		n = n / 10;
		l--;
	}
	if (neg == '-')
	{
		number[0] = '-';
	}
	else
	{
		number[0] = (n % 10) + '0';
	}
	return (number);
}

static int	lengthnbr(long n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		counter ++;
		n = -n;
	}
	while (n > 0)
	{
		counter ++;
		n = n / 10;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		len;

	if (n == 0)
	{
		return (ft_strdup("0"));
	}
	len = lengthnbr(n);
	number = (char *)malloc ((len + 1) * sizeof(char));
	if (!number)
	{
		return (NULL);
	}
	number = strinigfy(n, len, number);
	return (number);
}
