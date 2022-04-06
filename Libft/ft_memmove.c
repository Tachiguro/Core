/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:57:05 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/05 15:53:42 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	size_t		i;
	const char	*temp_src;
	char		*temp_dst;

	temp_src = (char *)src;
	temp_dst = (char *)dst;
	i = 0;
	if (temp_dst > temp_src)
	{
		while (len > 0)
		{
			temp_dst[len - 1] = temp_src[len - 1];
			len--;
		}
	}
	else if (temp_dst < temp_src)
	{
		while (i < len)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	return (dst);
}
