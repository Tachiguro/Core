/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:45:05 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/07 12:12:38 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new_str;

	if (s == NULL || f == NULL)
	{
		return (NULL);
	}
	i = 0;
	new_str = ft_strdup(s);
	if (!new_str)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		new_str[i] = (f)(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
