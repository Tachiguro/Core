/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:30:05 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/07 12:12:57 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*  Function: ft_strncmp                                                      */
/*  --------------------                                                      */
/*  The ft_strncmp() function compares the string pointed to, by s1 to the    */
/*  string pointed to by s2.                                                  */
/*                                                                            */
/*  s1: Pointer to the first string to be compared.                           */
/*  s2: Pointer to the second string to be compared.                          */
/*  n: The maximum number of characters to be compared.                       */
/*  return: If Return value < 0 then it indicates str1 is less than s2.       */
/*    If Return value > 0 then it indicates s2 is less than s1.               */
/*    If Return value = 0 then it indicates s1 is equal to s2.                */
/* ************************************************************************** */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	while (i < n - 1 && s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
