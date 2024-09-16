/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:36:37 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/15 18:26:01 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_resources(char *line, char *trimmed_line, char *map_str)
{
	free(line);
	free(trimmed_line);
	free(map_str);
}

char	*read_map_file(t_game *game, int fd)
{
	char	*line;
	char	*map_str;
	char	*temp;
	char	*trimmed_line;

	map_str = ft_strdup("");
	line = get_next_line(fd);
	if (!map_str || line == NULL)
		handle_error_exit(game, "Failed to read map!");
	while (line)
	{
		trimmed_line = ft_strtrim(line, " \n\t");
		if (!trimmed_line || ft_strlen(trimmed_line) == 0)
			handle_error_exit(game, "Map can't have empty lines!");
		temp = ft_strjoin(map_str, line);
		free_resources(line, trimmed_line, map_str);
		if (!temp)
			handle_error_exit(game, "Malloc failed during map concatenation!");
		map_str = temp;
		line = get_next_line(fd);
	}
	return (map_str);
}

void	split_map_into_grid(t_game *game, char *map_str)
{
	char	*trimmed_row;

	trimmed_row = NULL;
	game->map.grid = ft_split(map_str, '\n');
	free(map_str);
	if (game->map.grid == NULL)
		handle_error_exit(game, "Malloc failed during map split!");
	game->map.rows = 0;
	while (game->map.grid[game->map.rows])
	{
		trimmed_row = ft_strtrim(game->map.grid[game->map.rows], " \n\t");
		if (ft_strlen(trimmed_row) == 0)
		{
			free(trimmed_row);
			handle_error_exit(game, "Map contains empty lines!");
		}
		free(trimmed_row);
		game->map.rows++;
	}
	game->map.columns = ft_strlen(game->map.grid[0]);
	if (game->map.columns == 0)
	{
		handle_error_exit(game, "Map has no columns!");
	}
}

void	count_elements(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->num_exits = 0;
	game->num_coins = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.grid[y][x] == 'E')
				game->num_exits++;
			else if (game->map.grid[y][x] == 'C')
				game->num_coins++;
			else if (game->map.grid[y][x] == 'P')
				game->player_pos = (t_pos){x, y};
			x++;
		}
		y++;
	}
}

void	store_positions(t_game *game)
{
	int	y;
	int	x;
	int	exit_index;
	int	coin_index;

	y = 0;
	exit_index = 0;
	coin_index = 0;
	game->exits_pos = (t_pos *)malloc(sizeof(t_pos) * game->num_exits);
	game->coins_pos = (t_pos *)malloc(sizeof(t_pos) * game->num_coins);
	if (!game->exits_pos || !game->coins_pos)
		handle_error_exit(game, "Memory allocation failed for positions!");
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.grid[y][x] == 'E')
				game->exits_pos[exit_index++] = (t_pos){x, y};
			else if (game->map.grid[y][x] == 'C')
				game->coins_pos[coin_index++] = (t_pos){x, y};
			x++;
		}
		y++;
	}
}
