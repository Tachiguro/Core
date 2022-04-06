/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:32:36 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/06 11:30:01 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*	Function:ft_atoi														  */
/*	----------------														  */
/*	Converts a string to an integer.										  */
/*																			  */
/*	The atoi function skips all white-space characters at the beginning of 	  */
/*	the string, converts the subsequent characters as part of the number, and */
/*	then stops when it encounters the first character that isn't a number.	  */
/*																			  */
/*	*str: pointer to a string to convert to an integer.				  		  */
/*	return: the integer representation of a string.							  */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long	i;
	char	*s;
	long	result;
	int		sign;

	sign = 1;
	s = (char *)str;
	result = 0;
	i = 0;
	while (((s[i] >= 9) && (s[i] <= 13)) || (s[i] == 32))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] < 48 || s[i] > 57)
			return (sign * result);
		result = result * 10 + s[i] - 48;
		i++;
	}
	return (sign * result);
}
