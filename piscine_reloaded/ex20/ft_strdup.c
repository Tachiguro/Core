/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:55:12 by jherzog           #+#    #+#             */
/*   Updated: 2023/11/12 17:57:58 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*ft_strdup(char *src)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(src) + 1;
	new_str = (char *)malloc(sizeof(char) * len);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, src, len);
	return (new_str);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
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
