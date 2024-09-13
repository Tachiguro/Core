/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:28:26 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/13 19:33:13 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*output;
	size_t	len;

	len = nelem * elsize;
	output = malloc(len);
	if (!output)
		return (NULL);
	ft_bzero(output, len);
	return (output);
}
