/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:02:21 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/12 17:48:06 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	main(int argc, char **argv)
{
	char	*path;
	char	*number;

	path = NULL;
	number = NULL;
	path = "./dict/numbers.dict";
	if (argc == 2)
	{
		if (check_argv2(argv, path, &number) == 1 && argc == 2)
		{
			ft_putstr(" #ERROR: check_argv2\n");
			return (1);
		}
	}
	else if (argc == 3)
	{
		if (check_argv3(argv, &path, &number) == 1 && argc == 2)
		{
			ft_putstr(" #ERROR: check_argv2\n");
			return (1);
		}
	}
	else
	{
		ft_putstr(" #ERROR: not enoth arguments!\n");
		return (1);
	}
	ft_translate(number, path);
	return (0);
}

int	check_argv3(char **argv, char **path, char **number)
{
	char	*temp_number;
	char	*temp_path;

	temp_number = NULL;
	temp_path = NULL;
	if (dict_found(argv[1]) == -1)
	{
		ft_putstr(" #ERROR: dic at path not found!\n");
		return (1);
	}
	temp_path = (char *)malloc(ft_strlen(argv[1]) * sizeof(char) + 1);
	if (!temp_path)
	{
		ft_putstr(" #ERROR: Malloc path\n");
		return (1);
	}
	ft_strlcpy(temp_path, argv[1], ft_strlen(argv[1]) + 1);
	if (check_number(argv[2]) == -1 || ft_strlen(argv[2]) > 10)
	{
		ft_putstr(" #ERROR: number not correct!!!!!\n");
		return (1);
	}
	temp_number = (char *)malloc(ft_strlen(argv[2]) * sizeof(char) + 1);
	if (!temp_number)
	{
		ft_putstr(" #ERROR: Malloc number\n");
		return (1);
	}
	ft_strlcpy(temp_number, argv[2], ft_strlen(argv[2]) + 1);
	ft_putstr(" #Info: Change the dict <argv[1]> and trans the number<argv[2]>\n");
	*number = temp_number;
	*path = temp_path;
	return (0);
}

int	check_argv2(char **argv, char *path, char **number)
{
	char	*temp_number;

	temp_number = NULL;
	if (dict_found(path) == -1)
	{
		ft_putstr(" #ERROR: dic at path not found!\n");
		return (1);
	}
	if (check_number(argv[1]) == -1 || ft_strlen(argv[1]) > 10)
	{
		ft_putstr(" #ERROR: number not correct\n");
		return (1);
	}
	else
	{
		temp_number = (char *)malloc(ft_strlen(argv[1]) * sizeof(char) + 1);
		if (!temp_number)
		{
			ft_putstr(" #ERROR: Malloc number\n");
			return (1);
		}
		ft_strlcpy(temp_number, argv[1], ft_strlen(argv[1]) + 1);
		ft_putstr(" #Info: Work with our dict, trans the number<argv[1]>\n");
		*number = temp_number;
	}
	return (0);
}
