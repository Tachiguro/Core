/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:59:02 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/07 12:23:06 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*  Function: ft_strchr                                                       */
/*  --------------------                                                      */
/*  The ft_strchr() function Finds the first occurrence of ch                 */
/*  (after conversion to char as if by (char)ch) in the null-terminated byte  */
/*  string pointed to by str (each character interpreted as unsigned char).   */
/*  The terminating null character is considered to be a part of the string   */
/*  and can be found when searching for '\0'.                                 */
/*  The behavior is undefined if str is not a pointer to a null-terminated    */
/*  byte string.                                                              */
/*                                                                            */
/*  s: Pointer to the null-terminated byte string to be analyzed.             */
/*  c: Character to search for.                                               */
/*  return: Pointer to the found character in str, or null pointer if no such */
/*    character is found..                                                    */
/* ************************************************************************** */
char	*ft_strchr(const char *s, int c)
{
	while (*s || *s == (char)c)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}
