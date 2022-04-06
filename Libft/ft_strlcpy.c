/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:21:09 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/05 18:42:21 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		n;

	n = 0;
	if (dst == NULL || src == NULL)
	{
		return (0);
	}
	while (n < dstsize - 1 && src[n] != '\0' && dstsize > 0)
	{
		dst[n] = src[n];
		n++;
	}
	if (dstsize != 0)
		dst[n] = '\0';
	return (ft_strlen(src));
}
