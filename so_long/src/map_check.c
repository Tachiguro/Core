/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:02:35 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/14 23:41:37 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#define VALID_CHARS "01CEP"

int	check_rectangular(char **map)
{
	int		i;
	size_t	row_length;

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
	int	collectible_count;
	int	i;

	exit_count = 0;
	player_count = 0;
	collectible_count = 0;
	i = 0;
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
