/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:13:19 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/13 21:21:57 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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

static char	*join_helper(char *start, char *buff)
{
	char	*ptr;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!start)
		start = (char *)malloc(1 * sizeof(char));
	if (!start || !buff)
		return (NULL);
	ptr = (char *)malloc(1 + ft_strlen(start) + ft_strlen(buff) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (start[++i])
		ptr[i] = start[i];
	while (buff[++j])
		ptr[i + j] = buff[j];
	ptr[i + j] = '\0';
	free(start);
	return (ptr);
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
		buff_start = join_helper(buff_start, temp_buff);
	}
	free(temp_buff);
	temp_buff = extract_line(buff_start);
	buff_start = move_buffer_start(buff_start);
	return (temp_buff);
}

// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = 0;
// 	line = NULL;
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Can't open file!\n");
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	return (0);
// }
