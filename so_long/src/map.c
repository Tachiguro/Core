/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:22:22 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/13 21:28:08 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#define VALID_CHARS "01CEP"

int	check_rectangular(char **map)
{
	int i;
	size_t row_length;

	i = 0;
	row_length = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != row_length)
			return (1);
		i++;
	}
	return (0);
}

int	check_valid_chars(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(VALID_CHARS, map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_walls(char **map)
{
	int i;
	int last_row;
	int last_col;

	last_row = 0;
	while (map[last_row])
		last_row++;
	last_row -= 1;  // The index of the last row
	last_col = ft_strlen(map[0]) - 1;  // The index of the last column

	// Check top and bottom row
	for (i = 0; i <= last_col; i++)
	{
		if (map[0][i] != '1' || map[last_row][i] != '1')
			return (1);
	}

	// Check left and right column
	for (i = 0; i <= last_row; i++)
	{
		if (map[i][0] != '1' || map[i][last_col] != '1')
			return (1);
	}
	return (0);
}

static int	count_char(char *str, char c)
{
	int count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return count;
}

int	check_required_elements(char **map)
{
	int exit_count = 0;
	int player_count = 0;
	int collectible_count = 0;
	int i = 0;

	while (map[i])
	{
		exit_count += count_char(map[i], 'E');
		player_count += count_char(map[i], 'P');
		collectible_count += count_char(map[i], 'C');
		i++;
	}
	if (exit_count != 1 || player_count != 1 || collectible_count < 1)
		return (1);
	return (0);
}

char 	**parse_map(char *map_path)
{
	int		fd;
	char	*line;
	char	**map;
	char	*map_str;
	char	*temp;

	fd = 0;
	line = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map_str = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_strjoin(map_str, line);
		free(map_str);
		map_str = temp;
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(map_str, '\n');
	free(map_str);
	return (map);
}
