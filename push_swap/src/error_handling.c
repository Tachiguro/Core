/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:09:24 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/17 18:58:00 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_handling(t_stack *stack_a)
{
	if (stack_a->array != NULL)
	{
		printf("Error!!!!\n");
		free(stack_a->array);
	}
	exit(0);
}

bool	error_syntax(char *num)
{
	if (!(*num == '+' || *num == '-' || (*num >= '0' && *num <= '9')))
	{
		printf("Error:1\n");
		return (true);
	}
	if ((*num == '+' || *num == '-') && !(num[1] >= '0' && num[1] <= '9'))
	{
		printf("Error:2\n");
		return (true);
	}
	while (*++num)
	{
		if (!(*num >= '0' && *num <= '9'))
		{
			printf("Error:3\n");
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
			write(1, "Error:rep\n", 10);
			return (true);
		}
		i++;
	}
	return (false);
}
