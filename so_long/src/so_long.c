/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:13:59 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/13 21:28:35 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	handle_error_exit(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

static int	check_map(char **map)
{
	if (check_rectangular(map) != 0)
	{
		ft_printf("ERROR: maps is not rectingular!\n");
		return (1);
	}
	if (check_valid_chars(map) != 0)
	{
		ft_printf("ERROR: wrong chars in map!\n");
		return (1);
	}
	if (check_walls(map) != 0)
	{
		ft_printf("ERROR: map is not enclosed with walls!\n");
		return (1);
	}
	if (check_required_elements(map) != 0)
	{
		ft_printf("ERROR: Not enough or too much objects on map!\n");
		return (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	map = NULL;
	i = 0;
	if (argc != 2)
		handle_error_exit("ERROR: Not enouth arguments\nUsage: ./so_long <map.ber>");
	map = parse_map(argv[1]);
	if (map == NULL)
		handle_error_exit("ERROR:  Can't open map file.\n");
	if (check_map(map) == 0)
		ft_printf("MAP is ok!\n");
	else
		ft_printf("MAP is not ok!\n");
	while (map[i])
		free(map[i++]);
	free(map);
	return (0);
}
