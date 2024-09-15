/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:13:44 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/15 19:57:35 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include <fcntl.h>

# define ERROR_EXIT_COUNT 1
# define ERROR_PLAYER_COUNT 2
# define ERROR_COIN_COUNT 3

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		columns;
}	t_map;

typedef struct s_game
{
	t_map	map;
	t_pos	player_pos;
	t_pos	*exits_pos;
	t_pos	*coins_pos;
	int		moves;
	int		num_exits;
	int		num_coins;
}	t_game;

typedef struct	s_dfs_data
{
	char	**map;
	int		rows;
	int		cols;
	int		coins_found;
	int		exit_found;
}	t_dfs_data;

void	handle_error_exit(t_game *game, char *msg);
void	free_game_resources(t_game *game);

void	parse_map(t_game *game, char *map_path);

int		check_rectangular(char **map);
int		check_valid_chars(char **map);
int		check_walls(char **map);
int		check_required_elements(char **map);
int		check_empty_lines(char **map);
int		check_valid_path(t_game *game);

void	ft_print_map(char **map, int rows, int columns);

#endif
