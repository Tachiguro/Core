/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:42:37 by wrottger          #+#    #+#             */
/*   Updated: 2023/05/23 10:44:36 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	count_digits(int n)
{
	if (n / 10 == 0)
		return (1);
	return (1 + count_digits(n / 10));
}

static char	*make_int_min(void)
{
	char	*array;
	char	*result;

	array = "-2147483648";
	result = (char *) malloc(12);
	if (!result)
		return (NULL);
	ft_memcpy(result, array, 12);
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		digits;
	_Bool	negative;

	digits = count_digits(n);
	negative = 0;
	if (n < 0)
	{
		negative = 1;
		n *= -1;
		if (n == INT_MIN)
			return (make_int_min());
	}
	result = (char *) malloc(sizeof(char) * (digits + 1 + negative));
	if (!result)
		return (NULL);
	result[digits + negative] = '\0';
	while ((negative + digits--))
	{
		result[negative + digits] = (n % 10) + '0';
		n = n / 10;
	}
	if (negative)
		*result = '-';
	return (result);
}
