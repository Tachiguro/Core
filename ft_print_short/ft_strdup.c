/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:17:16 by jherzog           #+#    #+#             */
/*   Updated: 2022/05/10 20:10:08 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*new_str;
	char	*temp_str;

	len = ft_strlen(s1) + 1;
	temp_str = (char *)malloc(sizeof(char) * len);
	if (temp_str == 0)
		return (0);
	new_str = ft_memcpy(temp_str, s1, len);
	return (new_str);
}
