/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:44:52 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/15 00:10:53 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_player_count(char **map)
{
	int	y;
	int	x;
	int	player_count;

	y = 0;
	player_count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count != 1)
		return (1);
	return (0);
}
