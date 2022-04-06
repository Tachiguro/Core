/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:13:34 by jherzog           #+#    #+#             */
/*   Updated: 2021/10/08 12:39:36 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*output;
	int		len;

	len = count * size;
	output = malloc(len);
	if (!output)
	{
		return (NULL);
	}
	ft_bzero(output, len);
	return (output);
}
