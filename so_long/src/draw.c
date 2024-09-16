/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:29:03 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/15 23:50:41 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_assets(t_game *game)
{
	game->player.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER,
			&game->player.x, &game->player.y);
	if (!game->player.xpm_ptr)
		handle_error_exit(game, "Failed to load player image!");
	game->wall.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, TREE,
			&game->wall.x, &game->wall.y);
	if (!game->wall.xpm_ptr)
		handle_error_exit(game, "Failed to load tree image!");
	game->coin.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, COIN,
			&game->coin.x, &game->coin.y);
	if (!game->coin.xpm_ptr)
		handle_error_exit(game, "Failed to load coin image!");
	game->exit.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, EXIT,
			&game->exit.x, &game->exit.y);
	if (!game->exit.xpm_ptr)
		handle_error_exit(game, "Failed to load exit image!");
	game->floor.xpm_ptr = mlx_xpm_file_to_image(game->mlx_ptr, GRASS,
			&game->floor.x, &game->floor.y);
	if (!game->floor.xpm_ptr)
		handle_error_exit(game, "Failed to load floor image!");
}

static void	draw_helper(t_game *game, int y, int x)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->floor.xpm_ptr, x * PIXEL, y * PIXEL);
	if (game->map.grid[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall.xpm_ptr, x * PIXEL, y * PIXEL);
	else if (game->map.grid[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->coin.xpm_ptr, x * PIXEL, y * PIXEL);
	else if (game->map.grid[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->exit.xpm_ptr, x * PIXEL, y * PIXEL);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			draw_helper(game, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.xpm_ptr,
		game->player_pos.x * PIXEL, game->player_pos.y * PIXEL);
}
