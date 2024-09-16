/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:02:35 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/16 19:51:35 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#define VALID_CHARS "01CEP"

int	check_rectangular(char **map)
{
	int		i;
	size_t	row_length;
	char	*trimmed_row;

	i = 0;
	trimmed_row = ft_strtrim(map[0], " \n\t");
	row_length = ft_strlen(trimmed_row);
	free(trimmed_row);
	while (map[i])
	{
		trimmed_row = ft_strtrim(map[i], " \n\t");
		if (ft_strlen(trimmed_row) != row_length)
		{
			free(trimmed_row);
			return (1);
		}
		free(trimmed_row);
		i++;
	}
	return (0);
}

int	check_valid_chars(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_strchr(VALID_CHARS, map[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_walls(char **map)
{
	int	i;
	int	last_row;
	int	last_col;

	last_row = 0;
	while (map[last_row])
		last_row++;
	last_row -= 1;
	last_col = ft_strlen(map[0]) - 1;
	i = 0;
	while (i <= last_col)
	{
		if (map[0][i] != '1' || map[last_row][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i <= last_row)
	{
		if (map[i][0] != '1' || map[i][last_col] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	count_char(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int	check_required_elements(char **map)
{
	int	exit_count;
	int	player_count;
	int	coin_count;
	int	i;

	exit_count = 0;
	player_count = 0;
	coin_count = 0;
	i = 0;
	while (map[i])
	{
		exit_count += count_char(map[i], 'E');
		player_count += count_char(map[i], 'P');
		coin_count += count_char(map[i], 'C');
		i++;
	}
	if (exit_count != 1)
		return (ERROR_EXIT_COUNT);
	if (player_count != 1)
		return (ERROR_PLAYER_COUNT);
	if (coin_count < 1)
		return (ERROR_COIN_COUNT);
	return (0);
}
