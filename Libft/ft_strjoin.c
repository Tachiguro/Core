/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:41:03 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/07 12:11:56 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = (char *)malloc(len * sizeof(char));
	j = 0;
	i = 0;
	if (new_str == 0)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}
