/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:48:41 by wrottger          #+#    #+#             */
/*   Updated: 2023/05/23 12:18:09 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_count(char const *s, char c)
{
	int		i;
	int		count;
	int		flag;

	count = 0;
	flag = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

static char	*create_words(char const *s, int start, int end)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (str);
	i = start;
	j = 0;
	while (i < end)
	{
		str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

static char	**free_split(char **split, int j)
{
	j--;
	while (j)
		free(split[j--]);
	free(split[0]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	int		index;
	int		j;

	split = (char **)malloc((get_word_count(s, c) + 1) * sizeof(char *));
	if (!split)
		return (split);
	i = -1;
	index = -1;
	j = 0;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = create_words(s, index, i);
			if ((!split[j - 1]))
				return (free_split(split, j));
			index = -1;
		}
	}
	split[j] = 0;
	return (split);
}
