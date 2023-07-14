/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:57:05 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/05 15:53:42 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*  Function: ft_memmove                                                      */
/*  --------------------                                                      */
/*  The ft_memmove() function copies n bytes from memory area src to          */
/*    memory area dest.  The memory areas may overlap: copying takes          */
/*    place as though the bytes in src are first copied into a                */
/*    temporary array that does not overlap src or dest, and the bytes        */
/*    are then copied from the temporary array to dest.                       */
/*                                                                            */
/*  dst: This is a pointer to the destination array where the content is to   */
/*    be copied, type-casted to a pointer of type void*.                      */
/*  src: This is a pointer to the source of data to be copied, type-casted    */
/*    to a pointer of type void*.                                             */
/*  n: Number of bytes to be copied.                                          */
/* ************************************************************************** */
void	*ft_memmove(void *dst, void *src, size_t len)
{
	size_t		i;
	const char	*temp_src;
	char		*temp_dst;

	temp_src = (char *)src;
	temp_dst = (char *)dst;
	i = 0;
	if (temp_dst > temp_src)
	{
		while (len > 0)
		{
			temp_dst[len - 1] = temp_src[len - 1];
			len--;
		}
	}
	else if (temp_dst < temp_src)
	{
		while (i < len)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	return (dst);
}
