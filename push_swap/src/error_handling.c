/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:09:24 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/25 03:48:04 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_handling(t_stack *s_a)
{
	if (s_a->array != NULL)
	{
		write(2, "ErrorH\n", 7);
		free(s_a->array);
	}
	exit(0);
}

bool	error_syntax(char *num)
{
	if (!(*num == '+' || *num == '-' || (*num >= '0' && *num <= '9')))
	{
		write(2, "ErrorS1\n", 8);
		exit(0);
	}
	if ((*num == '+' || *num == '-') && !(num[1] >= '0' && num[1] <= '9'))
	{
		write(2, "ErrorS2\n", 8);
		exit(0);
	}
	while (*++num)
	{
		if (!(*num >= '0' && *num <= '9'))
		{
			write(2, "ErrorS3\n", 8);
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
			write(2, "ErrorR\n", 7);
			exit(0);
		}
		i++;
	}
	return (false);
}
