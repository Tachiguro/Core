/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:13:19 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/16 20:29:32 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*extract_line(char *buff_start)
{
	int		i;
	char	*line;

	if (!buff_start || !buff_start[0])
		return (NULL);
	i = 0;
	while (buff_start[i] && buff_start[i] != '\n')
		i++;
	if (buff_start[i] == '\n')
		line = (char *)malloc((i + 2) * sizeof(char));
	else
		line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buff_start[i] && buff_start[i] != '\n')
	{
		line[i] = buff_start[i];
		i++;
	}
	if (buff_start[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*move_buffer_start(char *buff_start)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	while (buff_start[i] && buff_start[i] != '\n')
		i++;
	if (!buff_start[i])
	{
		free(buff_start);
		return (NULL);
	}
	i++;
	new_buffer = (char *)malloc(ft_strlen(buff_start + i) + 1);
	if (!new_buffer)
		return (NULL);
	j = 0;
	while (buff_start[i + j])
	{
		new_buffer[j] = buff_start[i + j];
		j++;
	}
	new_buffer[j] = '\0';
	free(buff_start);
	return (new_buffer);
}

static char	*read_and_store(int fd, char **buff_start, char *temp_buff)
{
	int	bytes_read;

	bytes_read = 1;
	while ((!(*buff_start) || !ft_strchr(*buff_start, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, temp_buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			handle_read_error(temp_buff, buff_start);
			return (NULL);
		}
		temp_buff[bytes_read] = '\0';
		*buff_start = join_and_free(*buff_start, temp_buff);
		if (!(*buff_start))
		{
			handle_read_error(temp_buff, buff_start);
			return (NULL);
		}
	}
	return (*buff_start);
}

char	*get_next_line(int fd)
{
	char		*temp_buff;
	static char	*buff_start;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp_buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buff)
		return (NULL);
	if (!read_and_store(fd, &buff_start, temp_buff))
		return (NULL);
	free(temp_buff);
	temp_buff = extract_line(buff_start);
	buff_start = move_buffer_start(buff_start);
	return (temp_buff);
}
