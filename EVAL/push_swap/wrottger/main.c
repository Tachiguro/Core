/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:55:31 by wrottger          #+#    #+#             */
/*   Updated: 2023/07/14 11:53:42 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_ints(char **str_ints)
{
	size_t	i;

	i = 0;
	while (str_ints[i])
		i++;
	return (i);
}

static void	*free_split(char **split, int j)
{
	while (j > 0)
		free(split[--j]);
	free(split);
	return (NULL);
}

static void	choose_sort(struct s_stacks stacks)
{
	normalize_stacks(&stacks);
	if (sorted(stacks.a, stacks.a_size))
		;
	else if (stacks.size == 3)
		sort_three(stacks);
	else if (stacks.size > 3 && stacks.size < 7)
		sort_middle(stacks);
	else
		sort_stacks(stacks);
	free_stacks(stacks);
}

static void	*handle_argc2(
						struct s_stacks *stacks,
						char	**str_ints,
						char **argv)
{
	str_ints = ft_split(argv[1], ' ');
	if (!str_ints)
		exit(1);
	if (!malloc_stacks(stacks, count_ints(str_ints) + 1))
	{
		free_split(str_ints, count_ints(str_ints) + 1);
		exit(1);
	}
	return (str_ints);
}

int	main(int argc, char **argv)
{
	struct s_stacks	stacks;
	char			**str_ints;

	str_ints = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		str_ints = handle_argc2(&stacks, str_ints, argv);
	else
	{
		if (!malloc_stacks(&stacks, argc))
			return (1);
		str_ints = ++argv;
	}
	if (init_stacks(&stacks, str_ints) == -1)
	{
		if (argc == 2)
			free_split(str_ints, count_ints(str_ints) + 1);
		free_stacks(stacks);
		return (write(2, "Error\n", 6), -1);
	}
	if (argc == 2)
		free_split(str_ints, count_ints(str_ints) + 1);
	choose_sort(stacks);
}
