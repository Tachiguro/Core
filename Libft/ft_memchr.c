/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:35:47 by jherzog           #+#    #+#             */
/*   Updated: 2021/09/09 15:50:18 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*  Function: ft_memchr                                                       */
/*  --------------------                                                      */
/*  The ft_memchr() function searches for the first occurrence of the char c  */
/*  in the first n bytes of the string pointed to, by the argument s.         */
/*                                                                            */
/*  s: Pointer to the block of memory where the search is performed.          */
/*  c: Value to be passed as an int, but the function performs a byte per     */
/*    byte search using the unsigned char conversion of this value.           */
/*  return: Pointer to the matching byte or NULL if the character does not    */
/*    occur in the given memory area.                                         */
/* ************************************************************************** */
char	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*chr;
	char		*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char)c)
		{
			chr = (char *)&s[i];
			return (chr);
		}
		i++;
	}
	return (NULL);
}
