/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:29:29 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/13 21:19:24 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*output;
	int		total_len;

	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * total_len);
	if (str == NULL)
		return (NULL);
	output = str;
	str[0] = '\0';
	ft_strlcat(str, s1, total_len);
	ft_strlcat(str, s2, total_len);
	return (output);
}
