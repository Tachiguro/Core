/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:17:39 by wrottger          #+#    #+#             */
/*   Updated: 2023/07/12 18:38:26 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	count_bits(size_t n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n >>= 1;
	}
	return (count);
}

int	get_bit(size_t bit, int num)
{
	int	mask;

	mask = 1;
	mask = mask << bit;
	return (mask & num);
}

int	sorted(int	*stack, size_t len)
{
	while (--len)
		if (stack[len] > stack[len - 1])
			return (0);
	return (1);
}
