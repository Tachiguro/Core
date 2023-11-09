/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:47:45 by wrottger          #+#    #+#             */
/*   Updated: 2023/06/22 11:36:05 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	c = (char) c;
	while (*s != c && *s != '\0')
	{
		s++;
	}
	if (*s == c)
	{
		return ((char *) s);
	}
	else if (c == '\0')
	{
		return ((char *) s++);
	}
	else
	{
		return (NULL);
	}
}
