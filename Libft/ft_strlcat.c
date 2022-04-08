/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:39:46 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/05 18:37:46 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*  Function: ft_strlcat                                                      */
/*  --------------------                                                      */
/*  The ft_strlcat() function cancatenate src to string dst of size len.      */
/*                                                                            */
/*  dst: A pointer to the destination string.                                 */
/*  src: A pointer to the source string.                                      */
/*  len: The size of the destination buffer.                                  */
/*  return: The total length of the string initial length of dst plus         */
/*    the length of src. While this may seem somewhat confusing, it was done  */
/*    to make truncation detection simple.                                    */
/* ************************************************************************** */
size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (destlen >= len)
		return (len + srclen);
	j = destlen;
	while (j + 1 < len && src[i] != '\0')
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (destlen + srclen);
}
