/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:47:41 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/07 12:20:53 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*  Function: ft_strrchr                                                      */
/*  --------------------                                                      */
/*  The ft_strrchr() function searches for the last occurrence of the         */
/*  character c in the string pointed to, by the argument s.                  */
/*                                                                            */
/*  s: Pointer to the null-terminated byte string to be analyzed.             */
/*  c: Character to search for.                                               */
/*  return: Pointer to the found character in str, or null pointer if no such */
/*    character is found..                                                    */
/* ************************************************************************** */
char	*ft_strrchr(const char *s, int c)
{
	int			i;
	static char	*prt;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			prt = (char *)&s[i];
			return (prt);
		}
		i--;
	}
	return (NULL);
}
