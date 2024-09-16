/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:13:44 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/15 23:15:47 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include <fcntl.h>

# ifdef __linux__
    # include "../minilibx-linux/mlx.h"
	# define KEY_W              119
	# define KEY_A              97
	# define KEY_S              115
	# define KEY_D              100
	# define ARROW_UP           65362
	# define ARROW_LEFT         65361
	# define ARROW_DOWN         65364
	# define ARROW_RIGHT        65363
	# define KEY_ESC            65307
# else
	# include "../minilibx_opengl_20191021/mlx.h"
	# define KEY_W				13
	# define KEY_A				0
	# define KEY_S				1
	# define KEY_D				2
	# define ARROW_UP			126
	# define ARROW_LEFT			123
	# define ARROW_DOWN			125
	# define ARROW_RIGHT		124
	# define KEY_ESC			53
# endif

# define ERROR_EXIT_COUNT		1
# define ERROR_PLAYER_COUNT		2
# define ERROR_COIN_COUNT		3

# define PIXEL					32
# define PLAYER					"assets/player.xpm"
# define TREE					"assets/tree.xpm"
# define COIN					"assets/coin.xpm"
# define EXIT					"assets/exit.xpm"
# define GRASS					"assets/grass.xpm"

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

typedef struct	s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		wall;
	t_image		floor;
	t_image		coin;
	t_image		exit;
	t_image		player;
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

void	parse_map(t_game *game, char *map_path);
void	ft_print_map(char **map, int rows, int columns);

int		check_rectangular(char **map);
int		check_valid_chars(char **map);
int		check_walls(char **map);
int		check_required_elements(char **map);
int		check_empty_lines(char **map);
int		check_valid_path(t_game *game);

void	store_positions(t_game *game);
void	count_elements(t_game *game);
void	split_map_into_grid(t_game *game, char *map_str);
char	*read_map_file(t_game *game, int fd);

void	load_assets(t_game *game);
void	draw_map(t_game *game);

int		handle_key_press(int keycode, t_game *game);
int		exit_game(t_game *game);
void	free_game_resources(t_game *game);

#endif
