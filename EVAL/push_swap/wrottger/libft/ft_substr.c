/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:53:23 by wrottger          #+#    #+#             */
/*   Updated: 2023/05/19 10:13:32 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (str_len - start < len)
		len = str_len - start;
	if (start >= str_len || !len)
		len = 0;
	sub_str = (char *) malloc((len + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	if (!len)
		start = 0;
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
