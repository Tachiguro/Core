/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirzaza <emirzaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:55:52 by emirzaza          #+#    #+#             */
/*   Updated: 2023/07/14 13:10:26 by emirzaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_contains(char **args, int num, int i)
{
	while (args[i])
	{
		if (ft_atoi(args[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void	validate_num(int argc, char	**args, int i)
{
	long	num;

	while (args[i])
	{
		num = ft_atoi(args[i]);
		if (!ft_isnum(args[i]) || ft_contains(args, num, i + 1) 
			|| (num > 2147483647 || num < -2147483648)
			|| ft_strncmp(args[i], "-", ft_strlen(args[i])) == 0
			|| ft_strncmp(args[i], "+", ft_strlen(args[i])) == 0)
		{
			if (argc == 2)
				free_split(args);
			ft_error("Error");
		}
		i++;
	}
}

void	check_args(int argc, char **argz)
{
	char	**args;
	int		i;

	i = 0;
	if (argc < 2)
		exit (-1);
	else if (argc == 2)
	{
		if (ft_strlen(argz[1]) == 0)
			exit(-1);
		args = ft_split(argz[1], ' ');
		if (args[0] == 0)
		{
			free_split(args);
			ft_error("Error");
		}
	}
	else
	{
		i = 1;
		args = argz;
	}
	validate_num(argc, args, i);
	if (argc == 2)
		free_split(args);
}
