/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:47:39 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/15 23:55:32 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	handle_helper(t_game *game, t_pos new_pos)
{
	if (game->map.grid[new_pos.y][new_pos.x] == 'C')
	{
		game->map.grid[new_pos.y][new_pos.x] = '0';
		game->num_coins--;
	}
	else if (game->map.grid[new_pos.y][new_pos.x] == 'E')
	{
		if (game->num_coins > 0)
			return (0);
		else
		{
			ft_printf("All coins collected! You win!\n");
			exit_game(game);
		}
	}
	game->player_pos = new_pos;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	draw_map(game);
	return (1);
}

int	handle_key_press(int keycode, t_game *game)
{
	t_pos	new_pos;

	new_pos = game->player_pos;
	if (keycode == KEY_W || keycode == ARROW_UP)
		new_pos.y -= 1;
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
		new_pos.x -= 1;
	else if (keycode == KEY_S || keycode == ARROW_DOWN)
		new_pos.y += 1;
	else if (keycode == KEY_D || keycode == ARROW_RIGHT)
		new_pos.x += 1;
	else if (keycode == KEY_ESC)
		exit_game(game);
	if ((new_pos.y >= 0 && new_pos.y < game->map.rows)
		&& (new_pos.x >= 0 && new_pos.x < game->map.columns)
		&& (new_pos.y != game->player_pos.y || new_pos.x != game->player_pos.x))
	{
		if (game->map.grid[new_pos.y][new_pos.x] != '1')
		{
			if (handle_helper(game, new_pos) == 0)
				return (0);
		}
	}
	return (0);
}
