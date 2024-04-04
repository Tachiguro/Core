/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:13:08 by aortmann          #+#    #+#             */
/*   Updated: 2024/04/03 21:49:57 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *save, int i, int j)
{
	char	buff_str[BUFFER_SIZE + 1];
	int		buff_len;
	char	*temp;

	while (1)
	{
		buff_len = read(fd, buff_str, BUFFER_SIZE);
		if (buff_len == -1 || buff_len == 0)
		{
			free(save);
			return (NULL);
		}
		buff_str[buff_len] = '\0';
		temp = save;
		save = ft_strjoin(save, buff_str, i, j);
		free(temp);
		if (!save)
			return (NULL);
		if (ft_strchr(save, '\n') == 0)
		{
			free(save);
			break ;
		}
	}
	return (save);
}

char	*return_line(char *str)
{
	int		i;
	char	*ret;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	ret = (char *)malloc(i + 2);
	if (!ret)
		return (NULL);
	while (j < i)
	{
		ret[j] = str[j];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}


char	*del_last_line(char *str, int i, int j)
{
	char	*ret;

	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!ret)
	{
		free(str);
		return (NULL);
	}
	while (str[i] != '\0')
		ret[j++] = str[i++];
	ret[j] = '\0';
	free(str);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*ret;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_read_line(fd, save, 0, 0);
	if (!temp)
	{
		if (save)
			free(save);
		return (NULL);
	}
	save = temp;
	ret = return_line(save);
	save = del_last_line(save, 0, 0);
	if (!ret && save)
	{
		free(save);
		save = NULL;
	}
	return (ret);
}
