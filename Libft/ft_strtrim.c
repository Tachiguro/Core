/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:13:08 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/05 19:18:13 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*result;
	int		len;

	if (s1 == NULL || set == NULL)
	{
		return (NULL);
	}
	i = 0;
	len = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
	{
		i++;
	}
	while (len > 0 && ft_strchr(set, s1[len - 1]))
	{
		len --;
	}
	if (len < i)
	{
		return (ft_strdup("\0"));
	}
	result = ft_substr(s1, i, len - i);
	return (result);
}
