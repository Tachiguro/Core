/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:26:47 by wrottger          #+#    #+#             */
/*   Updated: 2023/05/18 12:55:52 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t maxlen)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen >= maxlen)
		return (maxlen + srclen);
	if (dstlen + srclen < maxlen)
	{
		ft_strlcpy(dst + dstlen, src, srclen + 1);
	}
	else
	{
		ft_strlcpy(dst + dstlen, src, maxlen - dstlen);
	}
	return (dstlen + srclen);
}
