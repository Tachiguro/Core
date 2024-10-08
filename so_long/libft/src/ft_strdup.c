/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:29:25 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/13 19:34:51 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(s1) + 1;
	new_str = (char *)malloc(sizeof(char) * len);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, len);
	return (new_str);
}
