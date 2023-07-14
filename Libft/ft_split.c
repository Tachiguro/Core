/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:29:20 by jherzog           #+#    #+#             */
/*   Updated: 2023/07/13 18:30:03 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_substrings(const char *s, char c)
{
	int	i;
	int	substring_count;

	i = 0;
	substring_count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			substring_count++;
		}
	}
	return (substring_count);
}

static char	*substrings(const char *s, char c, int *pos)
{
	int		i;
	char	*substring;

	while (s[*pos] == c)
		(*pos)++;
	i = *pos;
	while (s[i] != c && s[i] != '\0')
		i++;
	substring = ft_substr(s, *pos, i - *pos);
	if (!substring)
		return (0);
	*pos = i;
	return (substring);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		substring_count;
	int		pos;
	char	**string_array;

	if (s == 0)
		return (0);
	i = 0;
	pos = 0;
	substring_count = count_substrings(s, c);
	string_array = malloc((substring_count + 1) * sizeof(char *));
	if (!string_array)
		return (0);
	while (i < substring_count)
	{
		string_array[i] = substrings(s, c, &pos);
		i++;
	}
	string_array[i] = NULL;
	return (string_array);
}
