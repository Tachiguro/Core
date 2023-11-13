/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:51:03 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/15 17:25:17 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_sign(char *str, int pos)
{
	int	sign;

	sign = 0;
	while (str[pos] == '-' || str[pos] == '+')
	{
		if (str[pos] == '-')
			sign++;
		pos++;
	}
	if (sign % 2 == 0)
	{
		return (1);
	}
	return (-1);
}

int	ft_atoi(char *str)
{
	long	i;
	long	result;
	int		sign;

	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 12) || (str[i] == 32))
		i++;
	sign = check_sign(str, i);
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			return (sign * result);
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (sign * result);
}

#include <stdio.h>
int	main(void)
{
	int	i;
	i = 0;
	i = ft_atoi("0");
	printf("str:%i\n", i);
	return (0);
}