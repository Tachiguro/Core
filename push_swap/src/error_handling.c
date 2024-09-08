/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:09:24 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/08 19:52:37 by jherzog          ###   ########.fr       */
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
		exit(0);
	}
	if ((*num == '+' || *num == '-') && !(num[1] >= '0' && num[1] <= '9'))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	while (*++num)
	{
		if (!(*num >= '0' && *num <= '9'))
		{
			write(2, "Error\n", 6);
			exit(0);
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
			exit(0);
		}
		i++;
	}
	return (false);
}

void	free_stack(t_stack *stack)
{
	if (stack->array != NULL)
	{
		free(stack->array);
		stack->array = NULL;
	}
	if (stack->chunks != NULL)
	{
		free(stack->chunks);
		stack->chunks = NULL;
	}
}
