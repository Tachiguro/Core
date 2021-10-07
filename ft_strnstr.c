/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 22:09:00 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/07 12:13:39 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (counter < len && haystack[counter] != '\0')
	{
		i = 0;
		while ((haystack[counter + i] == needle[i]) && ((counter + i) < len))
		{
			if (haystack[counter + i] == needle[i] && needle[i + 1] == '\0')
			{
				return ((char *)haystack + counter);
			}
			i++;
		}
		counter++;
	}
	return (NULL);
}
