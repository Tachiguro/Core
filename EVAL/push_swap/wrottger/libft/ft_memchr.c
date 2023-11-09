/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:33:34 by wrottger          #+#    #+#             */
/*   Updated: 2023/05/17 16:03:14 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*us;

	if (n == 0)
		return (NULL);
	us = (unsigned char *) s;
	c = (unsigned char) c;
	if (*us == c)
		return (us);
	while (--n && *us != c)
		us++;
	if (*us == c)
		return (us);
	return (NULL);
}
