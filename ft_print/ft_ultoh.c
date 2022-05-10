/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:20:43 by jherzog           #+#    #+#             */
/*   Updated: 2022/05/10 17:41:42 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_length(unsigned long i)
{
	int	counter;

	counter = 0;
	while (i > 0)
	{
		i /= 10;
		counter++;
	}
	return (counter);
}

static char	int2hex(int i)
{
	if (i >= 0 && i <= 9)
	{
		return ('0' + i);
	}
	return ('a' + i - 10);
}

static void	trim(char *str, int len)
{
	char	*newstr;
	int		newlen;
	int		counter;

	counter = 0;
	newlen = 0;
	newstr = malloc(len * sizeof(char));
	while (counter != len)
	{
		if (str[counter] != '\0')
		{
			newstr[newlen] = str[counter];
			newlen++;
		}
			counter++;
	}
	newstr[newlen] = '\0';
	while (newlen >= 0)
	{
		str[newlen] = newstr[newlen];
		newlen--;
	}
}

char	*ft_ultoh(unsigned long number)
{
	int		len;
	int		hex;
	int		counter;
	char	*hexnumber;

	len = nbr_length(number);
	counter = len;
	hexnumber = malloc((len * sizeof(char)) + 1);
	while (counter >= 0)
	{
		hexnumber[counter] = '\0';
		counter--;
	}
	counter = len;
	while (number > 0)
	{
		hex = number % 16;
		number /= 16;
		hexnumber[counter -1] = int2hex(hex);
		counter--;
	}
	trim(hexnumber, len);
	return (hexnumber);
}
