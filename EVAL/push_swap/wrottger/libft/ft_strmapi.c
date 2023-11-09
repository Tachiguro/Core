/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:33:28 by wrottger          #+#    #+#             */
/*   Updated: 2023/05/22 16:44:15 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	str_len;
	char			*result;

	str_len = ft_strlen(s);
	result = (char *) malloc(sizeof(char) * (str_len + 1));
	if (!result)
		return (NULL);
	result[str_len] = '\0';
	while (str_len--)
		result[str_len] = f(str_len, s[str_len]);
	return (result);
}
