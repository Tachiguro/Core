/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:20:10 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/05 19:13:41 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	a;

	if (s == NULL)
	{
		return (0);
	}
	a = ft_strlen(&s[start]);
	if ((unsigned int)ft_strlen(s) < start)
	{
		return (ft_strdup(""));
	}
	if (a < len)
	{
		len = a;
	}
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (string == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(string, &s[start], len + 1);
	return (string);
}
