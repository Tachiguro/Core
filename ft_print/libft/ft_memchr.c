/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 21:35:47 by jherzog           #+#    #+#             */
/*   Updated: 2021/09/09 15:50:18 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*chr;
	char		*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
		{
			chr = (char *)&str[i];
			return (chr);
		}
		i++;
	}
	return (NULL);
}