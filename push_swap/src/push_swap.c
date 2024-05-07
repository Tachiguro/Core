/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:47:12 by jherzog           #+#    #+#             */
/*   Updated: 2024/05/07 17:55:06 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

// int	*create_stack(char *numbers, char *argv[])
// {
// 	int len;

// 	len = ft_strlen(numbers);
// }

int	check_correct_input(char *argv, char **strs)
{
	int	i;

	i = 0;
	strs = ft_split(argv, ' ');
	while (strs[i] && strs[i + 1])
	{
		if (ft_strncmp(strs[i], strs[i + 1], ft_strlen(strs[i])) == 0)
			exit(-1);
		i++;
	}

	return (1);
}

int	main(int argc, char **argv)
{
	char	**strs;
	int		i;

	i = 0;
	strs = NULL;
	if (argc == 1)
		exit(1);
	else
	{
		check_correct_input(*argv++, strs);
	}
	while (strs[i])
	{
		printf("argv:%s\n", strs[i]);
	}
	return (0);
}
