/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:44:00 by wrottger          #+#    #+#             */
/*   Updated: 2023/06/27 16:11:24 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strjoin(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;

	s2_len = ft_strlen(s2);
	if (!s1)
		return (ft_substr(s2, 0, s2_len));
	s1_len = ft_strlen(s1);
	result = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!result)
	{
		if (*s1)
			free(s1);
		return (NULL);
	}
	ft_memmove(result, s1, s1_len);
	ft_memmove(result + s1_len, s2, s2_len);
	result[s1_len + s2_len] = '\0';
	if (*s1)
		free(s1);
	return (result);
}
