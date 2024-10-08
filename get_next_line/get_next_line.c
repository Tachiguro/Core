/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:13:19 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/12 22:34:10 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *buff_start)
{
	int		i;
	char	*line;

	if (!buff_start || !buff_start[0])
		return (NULL);
	i = 0;
	while (buff_start[i] && buff_start[i] != '\n')
		i++;
	line = (char *)malloc(1 + (++i) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buff_start[i] && buff_start[i] != '\n')
	{
		line[i] = buff_start[i];
		i++;
	}
	if (buff_start[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*move_buffer_start(char	*buff_start)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff_start[i] && buff_start[i] != '\n')
		i++;
	if (buff_start[i] == '\0')
	{
		free(buff_start);
		return (NULL);
	}
	i += (buff_start[i] == '\n');
	new_buffer = (char *)malloc(1 + ft_strlen(buff_start) - i);
	if (!new_buffer)
		return (NULL);
	while (buff_start[i + j])
	{
		new_buffer[j] = buff_start[i + j];
		j++;
	}
	new_buffer[j] = '\0';
	free(buff_start);
	return (new_buffer);
}

static void	handle_read_error(char *temp_buff, char **buffer_start_ptr)
{
	free(temp_buff);
	free(*buffer_start_ptr);
	*buffer_start_ptr = NULL;
}

char	*get_next_line(int fd)
{
	char		*temp_buff;
	int			bytes_read;
	static char	*buff_start;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	temp_buff = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!temp_buff)
		return (NULL);
	while ((!buff_start || !(ft_strchr(buff_start, '\n'))) && bytes_read != 0)
	{
		bytes_read = read(fd, temp_buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			handle_read_error(temp_buff, &buff_start);
			return (NULL);
		}
		temp_buff[bytes_read] = '\0';
		buff_start = ft_strjoin(buff_start, temp_buff);
	}
	free(temp_buff);
	temp_buff = extract_line(buff_start);
	buff_start = move_buffer_start(buff_start);
	return (temp_buff);
}
