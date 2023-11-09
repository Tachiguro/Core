/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:07:01 by wrottger          #+#    #+#             */
/*   Updated: 2023/05/17 13:07:34 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	c = (char) c;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[i] != c && i != 0)
		i--;
	if (s[i] == c)
	{
		return ((char *)&s[i]);
	}
	else
	{
		return (NULL);
	}
}
