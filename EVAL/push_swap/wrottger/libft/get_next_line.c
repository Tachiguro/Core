/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:08:17 by wrottger          #+#    #+#             */
/*   Updated: 2023/06/27 16:10:34 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	read_buffer(int fd, char buffer[BUFFER_SIZE + 1])
{
	ssize_t		return_size;

	return_size = read(fd, buffer, BUFFER_SIZE);
	if (return_size >= 0)
		buffer[return_size] = '\0';
	return (return_size);
}

void	*handle_r_s(ssize_t r_s, char buffer[BUFFER_SIZE + 1], char *line)
{
	size_t	i;

	i = BUFFER_SIZE;
	if (r_s < 0)
	{
		while (i--)
			*buffer++ = 0;
		free(line);
		return (NULL);
	}
	if (r_s == 0)
		while (i--)
			*buffer++ = 0;
	return ((void *) 1);
}

void	*finish_line(char *line, char buffer[BUFFER_SIZE + 1], int return_s)
{
	size_t		newline_idx;
	char		*substr;

	if (!handle_r_s(return_s, buffer, line))
		return (NULL);
	newline_idx = return_s;
	if (ft_strchr(buffer, '\n'))
		newline_idx = ft_strchr(buffer, '\n') - buffer;
	substr = ft_substr(buffer, 0, newline_idx + 1);
	if (!substr)
	{
		if (line)
			free(line);
		if (substr)
			free(substr);
		return (NULL);
	}
	line = gnl_strjoin(line, substr);
	free(substr);
	if (!line)
		return (NULL);
	ft_memmove(buffer, buffer + newline_idx + 1, BUFFER_SIZE - newline_idx);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		return_size;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (*buffer)
		return_size = ft_strlen(buffer);
	else
		return_size = read_buffer(fd, buffer);
	if (return_size <= 0)
		return (NULL);
	line = NULL;
	while (!(ft_strchr(buffer, '\n')) && 0 < return_size)
	{
		line = gnl_strjoin(line, buffer);
		if (!line)
			return (NULL);
		return_size = read_buffer(fd, buffer);
	}
	return (finish_line(line, buffer, return_size));
}
