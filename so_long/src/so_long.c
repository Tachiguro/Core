/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:13:59 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/14 00:30:20 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h" //remove -g for optimization!!!!!!!!!!!!!!!!!!

static void	handle_error_exit(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

static char	**parse_map(char *map_path)
{
	int		fd;
	char	*line;
	char	**map;
	char	*map_str;
	char	*temp;

	fd = 0;
	line = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map_str = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_strjoin(map_str, line);
		free(map_str);
		map_str = temp;
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(map_str, '\n');
	free(map_str);
	return (map);
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
		return (1);
	}
	if (check_valid_path(map) != 0)
	{
		ft_printf("ERROR: No path to C and/or E\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game game;
	char	**map;
	int		i;

	i = 0;
	if (argc != 2)
		handle_error_exit("ERROR: Not enouth arguments.");
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		handle_error_exit("ERROR: map doesn't end with \".ber\"");
	game.map.grid = parse_map(argv[1]);
	if (map == NULL)
		handle_error_exit("ERROR:  Can't open map file.");
	if (check_map(game.map.grid) == 0)
		ft_printf("MAP is ok!\n");
	while (game.map.grid[i])
		free(map[i++]);
	free(map);
	return (0);
}
