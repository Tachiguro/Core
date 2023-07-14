/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 16:52:34 by jherzog           #+#    #+#             */
/*   Updated: 2021/09/09 18:24:18 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ************************************************************************** */
/*  Function: ft_memcpy                                                       */
/*  --------------------                                                      */
/*  The ft_memcpy() function copies n bytes from memory area src to           */
/*  memory area dest.  The memory areas must not overlap.                     */
/*                                                                            */
/*  dst: This is pointer to the destination array where the content is to be  */
/*    copied, type-casted to a pointer of type void*.                         */
/*  src: This is pointer to the source of data to be copied, type-casted to   */
/*    a pointer of type void*.                                                */
/*  n: Number of bytes to fill.                                               */
/* ************************************************************************** */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*temp_src;
	char		*temp_dst;

	temp_src = (char *)src;
	temp_dst = (char *)dst;
	i = 0;
	while (i < n)
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	return (dst);
}
