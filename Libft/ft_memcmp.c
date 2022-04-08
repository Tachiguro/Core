/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:40:28 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/05 18:26:44 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*  Function: ft_memcmp                                                       */
/*  --------------------                                                      */
/*  The ft_memcmp() function compares the first n bytes of memory area s1     */
/*  and memory area s2.                                                       */
/*                                                                            */
/*  s1: This is the pointer to a block of memory.                             */
/*  s2: This is the pointer to a block of memory.                             */
/*  n: This is the number of bytes to be compared.                            */
/*  return: If Return value < 0 then it indicates s1 is less than s2.         */
/*    If Return value > 0 then it indicates s2 is less than s1.               */
/*    If Return value = 0 then it indicates s1 is equal to s2.                */
/* ************************************************************************** */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}
