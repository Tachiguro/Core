/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:13:59 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/15 19:54:46 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h" //remove -g for optimization!!!!!!!!!!!!!!!!!!!!!!!

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

static void	check_args(t_game *game, int argc, char *argv)
{
	if (argc < 2)
		handle_error_exit(game, "Not enouth arguments!");
	else if (argc > 2)
		handle_error_exit(game, "Too much arguments!");
	if (ft_strncmp(&argv[ft_strlen(argv) - 4], ".ber", 4) != 0)
		handle_error_exit(game, "Map doesn't end with \".ber\"");
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		handle_error_exit(game, "Memory allocation failed for game structure!");
	check_args(game, argc, argv[1]);
	parse_map(game, argv[1]);
	if (game->map.grid == NULL)
		handle_error_exit(game, "Can't open map file.");
	check_map(game);
	free_game_resources(game);
	return (0);
}
