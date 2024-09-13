/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:29:05 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/13 19:34:06 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*temp_src;
	char		*temp_dst;

	temp_src = (char *)src;
	temp_dst = (char *)dst;
	if (!dst && !src && n > 0)
		return (0);
	while (n--)
		*temp_dst++ = *temp_src++;
	return (dst);
}
