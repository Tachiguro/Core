/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:47:12 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/17 19:10:14 by jherzog          ###   ########.fr       */
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
	print_stacks(&stack_a, &stack_b);
	if (!stack_sorted(&stack_a))
	{
		write(1, "\tKO\n", 4);
		if (stack_a.len == 2)
			s_a(&stack_a);
		else
		{
			push_swap(&stack_a, &stack_b);
			print_stacks(&stack_a, &stack_b);
		}
	}
	else
		write(1, "\tOK\n", 4);
	free(stack_a.array);
	return (0);
}
