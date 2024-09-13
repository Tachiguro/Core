/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:29:37 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/13 19:35:14 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = ft_strdup(s);
	if (!new_str || !s || !f)
		return (NULL);
	while (new_str[i] != '\0')
	{
		new_str[i] = f(i, new_str[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
