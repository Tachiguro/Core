/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:13:24 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/16 21:57:35 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*t_stc;
	int			i;

	i = -1;
	t_stc = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!t_stc)
		return (NULL);
	while (++i < ac)
	{
		t_stc[i].size = ft_strlen(av[i]);
		t_stc[i].str = av[i];
		t_stc[i].copy = ft_strdup(av[i]);
	}
	t_stc[i].str = 0;
	t_stc[i].copy = 0;
	return (t_stc);
}
