/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:16:40 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/14 18:27:46 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_sorted(int *stack, int stack_len)
{
	int	i;

	i = 0;
	while (i < stack_len - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}

	return (1);
}

// char	*stack_sort(int *stack_a, int stack_a_len)
// {
// 	char	*result;
// 	int		*stack_b;
// 	int		stack_b_len;

// 	stack_b_len = stack_a_len;

// 	return (result);
// }
