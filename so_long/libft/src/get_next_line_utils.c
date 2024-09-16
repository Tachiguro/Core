/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:13:19 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/15 18:09:22 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	handle_read_error(char *temp_buff, char **buffer_start_ptr)
{
	free(temp_buff);
	if (*buffer_start_ptr)
	{
		free(*buffer_start_ptr);
		*buffer_start_ptr = NULL;
	}
}

char	*copy_and_join(char *ptr, char *start, char *buff)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (start[++i])
		ptr[i] = start[i];
	while (buff[++j])
		ptr[i + j] = buff[j];
	ptr[i + j] = '\0';
	return (ptr);
}

char	*join_and_free(char *start, char *buff)
{
	char	*ptr;

	if (!start)
	{
		start = (char *)malloc(1);
		if (!start)
			return (NULL);
		start[0] = '\0';
	}
	ptr = (char *)malloc(ft_strlen(start) + ft_strlen(buff) + 1);
	if (!ptr)
	{
		free(start);
		return (NULL);
	}
	ptr = copy_and_join(ptr, start, buff);
	free(start);
	return (ptr);
}
