/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:48:56 by wrottger          #+#    #+#             */
/*   Updated: 2023/05/18 10:55:04 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	str_len;
	char	*new_str;

	str_len = ft_strlen(s1) + 1;
	new_str = ft_calloc(sizeof(char), str_len);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, str_len + 1);
	return (new_str);
}
