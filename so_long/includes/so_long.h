/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:13:44 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/13 20:31:16 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include <fcntl.h>

char 	**parse_map(char *map_path);
int		check_rectangular(char **map);
int		check_valid_chars(char **map);
int		check_walls(char **map);
int		check_required_elements(char **map);


#endif
