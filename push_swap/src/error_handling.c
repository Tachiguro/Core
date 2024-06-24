/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:09:24 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/24 13:56:47 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_handling(t_stack *s_a)
{
	if (s_a->array != NULL)
	{
		write(2, "Error\n", 6);
		free(s_a->array);
	}
	exit(0);
}

bool	error_syntax(char *num)
{
	if (!(*num == '+' || *num == '-' || (*num >= '0' && *num <= '9')))
	{
		write(2, "Error\n", 6);
		return (true);
	}
	if ((*num == '+' || *num == '-') && !(num[1] >= '0' && num[1] <= '9'))
	{
		write(2, "Error\n", 6);
		return (true);
	}
	while (*++num)
	{
		if (!(*num >= '0' && *num <= '9'))
		{
			write(2, "Error\n", 6);
			return (true);
		}
	}
	return (false);
}

bool	error_rep(t_stack *stack, int nbr)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->array[i] == nbr)
		{
			write(2, "Error\n", 6);
			return (true);
		}
		i++;
	}
	return (false);
}
