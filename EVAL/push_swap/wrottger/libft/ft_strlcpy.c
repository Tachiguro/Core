/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:35:53 by wrottger          #+#    #+#             */
/*   Updated: 2023/05/16 19:17:54 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	remaining_size;
	size_t	src_length;

	src_length = ft_strlen(src);
	if (size == 0)
		return (src_length);
	remaining_size = size;
	while (*src != '\0' && remaining_size > 1)
	{
		*dest++ = *src++;
		remaining_size--;
	}
	*dest = '\0';
	return (src_length);
}
