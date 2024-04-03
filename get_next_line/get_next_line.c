/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 05:31:35 by jherzog           #+#    #+#             */
/*   Updated: 2024/04/03 15:54:11 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	cleanup(char **str, void *content)
{
	if (*str)
	{
		free(*str);
		*str = (char *)content;
	}
}

static int	fill_buffer(char **buff, int fd)
{
	char	*temp;
	char	*buffer;
	int		counter;

	temp = NULL;
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (-1);
	counter = read(fd, buffer, BUFFER_SIZE);
	if (counter < 1)
	{
		if (buffer)
			cleanup(&buffer, NULL);
		if (counter == -1)
			cleanup(buff, NULL);
		return (counter);
	}
	buffer[counter] = '\0';
	temp = *buff;
	*buff = ft_strjoin(temp, buffer);
	if (!*buff)
	{
		cleanup(&temp, NULL);
		cleanup(&buffer, NULL);
		return (-1);
	}
	if (ft_strlen(temp))
		cleanup(&temp, NULL);
	cleanup(&buffer, NULL);
	return (counter);
}

static void	close_line_n(char **buff, char **line, int counter)
{
	char	*temp;
	size_t	i;

	i = 0;
	while ((*buff)[i] != '\n' && (*buff)[i])
		i++;
	*line = ft_substr(*buff, 0, i + 1);
	temp = *buff;
	if (counter > 0)
		*buff = ft_substr(temp, i + 1, ft_strlen(temp));
	cleanup(&temp, NULL);
}

static int	close_gnl(char **buff, char **line, int counter)
{
	if (ft_strchr(*buff, '\n'))
	{
		close_line_n(&*buff, &*line, counter);
		if (ft_strlen(*buff) == 0)
			cleanup(&*buff, "");
	}
	else
	{
		if (!ft_strlen(*buff) && counter == 0)
			return (0);
		*line = ft_strdup(*buff);
		cleanup(&*buff, NULL);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			counter;

	counter = BUFFER_SIZE;
	if (buffer == NULL || fd < 0 || counter <= 0)
		return (NULL);
	while (counter > 0 && !ft_strchr(buffer, '\n'))
	{
		counter = fill_buffer(&buffer, fd);
		if (counter < 0)
			return (NULL);
	}
	if (!close_gnl(&buffer, &line, counter))
		return (NULL);
	return (line);
}
