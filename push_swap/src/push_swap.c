/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:47:12 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/20 03:29:20 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	init_stacks(&stack_a, &stack_b);
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		create_stack_a(argv[1], &stack_a);
	else
		create_stack_a(join_args(argv), &stack_a);
	if (!stack_a_sorted(&stack_a))
	{
		stack_b.len = stack_b.top;
		stack_b.array = (int *)malloc(sizeof(int) * stack_a.top);
		if (!stack_b.array)
			exit(1);
		sort(&stack_a, &stack_b);
		free(stack_b.array);
	}
	free(stack_a.array);
	return (0);
}
