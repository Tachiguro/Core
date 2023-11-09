/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:00:06 by wrottger          #+#    #+#             */
/*   Updated: 2023/05/19 13:38:14 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	str_len;
	size_t	trimmed_len;
	char	*result;

	str_len = ft_strlen(s1);
	start = 0;
	end = str_len;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > 0 && ft_strchr(set, s1[end]))
		end--;
	if (end < start)
		return (ft_memset(malloc(sizeof(char)), '\0', 1));
	trimmed_len = end - start;
	result = ft_substr(&s1[start], 0, trimmed_len + 1);
	if (!result)
		return (NULL);
	return (result);
}
