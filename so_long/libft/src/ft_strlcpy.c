/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:29:33 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/13 19:35:06 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;

	n = 0;
	while (n < size - 1 && src[n] != '\0' && size > 0)
	{
		dst[n] = src[n];
		n++;
	}
	if (size != 0)
		dst[n] = '\0';
	return (ft_strlen(src));
}
