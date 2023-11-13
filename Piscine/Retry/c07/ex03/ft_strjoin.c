/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:28:42 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/14 01:54:29 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	sslen(int size, char **strs)
{
	int	len;
	int	i;

	len = 0;
	while (size > 0)
	{
		i = 0;
		while (strs[size - 1][i] != '\0')
		{
			i++;
			len++;
		}
		size--;
	}
	return (len);
}

int	slen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = (char *)malloc(slen(src) * sizeof(char) + 1);
	while (src[i] != '\0')
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	add_sep(char *str, char *sep, int *j)
{
	int	i;
	int	j_cnt;
	int	len;

	j_cnt = *j;
	i = 0;
	len = slen(sep);
	while (i < len)
	{
		str[j_cnt] = sep[i];
		j_cnt++;
		i++;
	}
	*j = j_cnt;
}

char	*ft_strjoin(int s, char **strs, char *sep)
{
	char	*new_str;
	int		cnt;
	int		i;
	int		j;

	cnt = 0;
	j = 0;
	new_str = malloc(sizeof(char) * sslen(s, strs) + (s - 1) * slen(sep) + 1);
	if (!new_str || s < 1)
		return (ft_strdup(""));
	while (cnt < s)
	{
		i = -1;
		while (strs[cnt][++i] != '\0')
		{
			new_str[j] = strs[cnt][i];
			j++;
		}
		if (cnt < s - 1)
			add_sep(new_str, sep, &j);
		cnt++;
	}
	new_str[j] = '\0';
	return (new_str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int		size = 3;
// 	char	*strs[] = {"uiae", "tduriane", "tudiranedtruina"};
// 	char	*new_str;

// 	new_str = ft_strjoin(size, strs, "_|_");
// 	printf(">%s<\n", new_str);
// 	return (0);
// }