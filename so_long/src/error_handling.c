/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:33:56 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/16 21:08:59 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game_resources(t_game *game)
{
	int	i;

	if (game->map.grid)
	{
		i = 0;
		while (game->map.grid[i])
			free(game->map.grid[i++]);
		free(game->map.grid);
	}
	if (game->exits_pos)
		free(game->exits_pos);
	if (game->coins_pos)
		free(game->coins_pos);
	if (game->player.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.xpm_ptr);
	if (game->wall.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	if (game->coin.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->coin.xpm_ptr);
	if (game->floor.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	if (game->exit.xpm_ptr)
		mlx_destroy_image(game->mlx_ptr, game->exit.xpm_ptr);
}

void	handle_error_exit(t_game *game, char *msg)
{
	ft_printf("ERROR: %s\n", msg);
	free_game_resources(game);
	exit(1);
}

int	exit_game(t_game *game)
{
	ft_printf("Quit game.\n");
	free_game_resources(game);
	exit(0);
	return (0);
}
