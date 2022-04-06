/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:25:35 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/05 19:27:46 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	ptr = (char *)b;
	j = len;
	while (i < j)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}
