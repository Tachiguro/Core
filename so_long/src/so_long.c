/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:13:59 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/15 23:55:59 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse_map(t_game *game, char *map_path)
{
	int		fd;
	char	*map_str;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		handle_error_exit(game, "Failed to open map file!");
	map_str = read_map_file(game, fd);
	split_map_into_grid(game, map_str);
	count_elements(game);
	store_positions(game);
	if (close(fd) == -1)
		handle_error_exit(game, "Failed to close the map file!");
}

static void	check_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.grid == NULL || game->map.grid[0] == NULL)
		handle_error_exit(game, "Map is empty!");
	if (game->map.rows < 3 || game->map.columns < 3)
		handle_error_exit(game, "Map is too small to be valid!");
	if (check_rectangular(game->map.grid) != 0)
		handle_error_exit(game, "Map is not rectingular!");
	if (check_valid_chars(game->map.grid) != 0)
		handle_error_exit(game, "Wrong chars in map!");
	if (check_walls(game->map.grid) != 0)
		handle_error_exit(game, "Map is not enclosed with walls!");
	i = check_required_elements(game->map.grid);
	if (i == ERROR_EXIT_COUNT)
		handle_error_exit(game, "Map need one exit!");
	if (i == ERROR_PLAYER_COUNT)
		handle_error_exit(game, "Map need one player!");
	if (i == ERROR_COIN_COUNT)
		handle_error_exit(game, "Map need at least one coin!");
	if (check_valid_path(game) != 0)
		handle_error_exit(game, "No path to C and/or E");
}

static void	check_args(t_game *game, int argc, char **argv)
{
	int	len;

	len = 0;
	if (argc < 2)
		handle_error_exit(game, "Not enouth arguments!");
	else if (argc > 2)
		handle_error_exit(game, "Too much arguments!");
	len = ft_strlen(argv[1]);
	if (len < 5)
		handle_error_exit(game, "Map name too short!");
	if (ft_strncmp(&argv[1][len - 4], ".ber", 4) != 0)
		handle_error_exit(game, "Map doesn't end with \".ber\"!");
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	game = (t_game *)ft_calloc(sizeof(t_game), 1);
	if (!game)
		handle_error_exit(game, "Memory allocation failed for game structure!");
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		handle_error_exit(game, "Failed to initialize MLX!");
	check_args(game, argc, argv);
	parse_map(game, argv[1]);
	if (game->map.grid == NULL)
		handle_error_exit(game, "Can't open map file.");
	check_map(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns * 32,
			game->map.rows * 32, "so_long");
	if (!game->win_ptr)
		handle_error_exit(game, "Failed to create window!");
	load_assets(game);
	draw_map(game);
	mlx_key_hook(game->win_ptr, handle_key_press, game);
	mlx_hook(game->win_ptr, 17, 0, exit_game, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
