/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:33:59 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/16 20:48:06 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**copy_map(char **map, int rows)
{
	char	**map_copy;
	int		i;

	map_copy = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[rows] = NULL;
	return (map_copy);
}

static void	dfs(t_dfs_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->cols || y >= data->rows
		|| data->map[y][x] == '1' || data->map[y][x] == 'V')
		return ;
	if (data->map[y][x] == 'C')
		data->coins_found++;
	if (data->map[y][x] == 'E' && data->coins_found == data->total_coins)
		data->exit_found = 1;
	data->map[y][x] = 'V';
	dfs(data, x + 1, y);
	dfs(data, x - 1, y);
	dfs(data, x, y + 1);
	dfs(data, x, y - 1);
}

int	check_valid_path(t_game *game)
{
	char		**map_copy;
	t_dfs_data	data;
	int			i;

	data.coins_found = 0;
	data.exit_found = 0;
	data.total_coins = game->num_coins;
	data.rows = game->map.rows;
	data.cols = game->map.columns;
	map_copy = copy_map(game->map.grid, game->map.rows);
	if (!map_copy)
		handle_error_exit(game, "Failed to copy map!");
	data.map = map_copy;
	dfs(&data, game->player_pos.x, game->player_pos.y);
	i = 0;
	while (i < game->map.rows)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
	if (data.coins_found == game->num_coins && data.exit_found)
		return (0);
	return (1);
}
