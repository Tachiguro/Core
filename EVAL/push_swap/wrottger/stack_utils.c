/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:21:07 by wrottger          #+#    #+#             */
/*   Updated: 2023/07/14 12:40:37 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*malloc_stacks(struct s_stacks *stacks, int argc)
{
	stacks->size = argc - 1;
	stacks->a = (int *) ft_calloc(sizeof(int), (argc));
	if (!stacks->a)
		return (NULL);
	stacks->b = (int *) ft_calloc(sizeof(int), argc);
	if (!stacks->b)
	{
		free(stacks->a);
		return (NULL);
	}
	return (stacks->a);
}

static int	check_argv(char *str)
{
	if (!*str)
		return (-1);
	if (*str == '-')
	{
		if (++str == 0
			|| (ft_strlen(str) == ft_strlen("2147483648")
				&& 0 < ft_strncmp(str, "2147483648", ft_strlen("2147483647"))))
			return (-1);
	}
	else
		if ((*str == '+' && ++str == 0)
			|| (ft_strlen(str) == ft_strlen("2147483647")
				&& 0 < ft_strncmp(str, "2147483647", ft_strlen("2147483647"))))
			return (-1);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (-1);
		str++;
	}
	return (1);
}

int	init_stacks(struct s_stacks *stacks, char **argv)
{
	int	i;
	int	j;

	if (*argv == NULL)
		return (-1);
	i = stacks->size - 1;
	stacks->a_size = stacks->size;
	stacks->b_size = 0;
	while (i >= 0)
	{
		if (check_argv(*argv) == -1)
			return (-1);
		stacks->a[i] = ft_atoi(*argv);
		j = stacks->size;
		while (--j > i)
			if (stacks->a[j] == stacks->a[i])
				return (-1);
		stacks->b[i] = 0;
		i--;
		argv++;
	}
	return (1);
}

void	free_stacks(struct s_stacks stacks)
{
	free(stacks.a);
	free(stacks.b);
}

void	normalize_stacks(struct s_stacks *stacks)
{
	size_t	i;
	size_t	j;
	int		smallest_index;

	i = 1;
	while (i < stacks->size + 1)
	{
		j = 0;
		smallest_index = -1;
		while (j < stacks->size)
		{
			if (stacks->b[j] == 0)
			{
				if (smallest_index == -1)
					smallest_index = j;
				if (stacks->a[j] < stacks->a[smallest_index])
					smallest_index = j;
			}
			j++;
		}
		stacks->b[smallest_index] = i;
		i++;
	}
	ft_memcpy(stacks->a, stacks->b, stacks->size * sizeof(int));
	ft_memset(stacks->b, 0, stacks->size * sizeof(int));
}
