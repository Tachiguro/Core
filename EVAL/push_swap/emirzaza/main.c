/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirzaza <emirzaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:00:52 by emirzaza          #+#    #+#             */
/*   Updated: 2023/07/11 15:06:16 by emirzaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char	**argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	check_args(argc, argv);
	stack_a = fill_stack(argc, argv);
	index_stack(&stack_a);
	if (is_sorted(&stack_a))
	{
		ft_clear_stack(&stack_a);
		return (0);
	}
	stack_b = NULL;
	sort(&stack_a, &stack_b);
	ft_clear_stack(&stack_a);
	ft_clear_stack(&stack_b);
	return (0);
}
