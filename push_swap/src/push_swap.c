/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:47:12 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/23 23:28:58 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	s_a;
	t_stack	s_b;

	init_stacks(&s_a, &s_b);
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		create_s_a(argv[1], &s_a);
	else
		create_s_a(join_args(argv), &s_a);
	if (!s_a_sorted(&s_a))
	{
		s_b.len = s_b.top;
		s_b.array = (int *)malloc(sizeof(int) * s_a.top);
		if (!s_b.array)
			exit(1);
		sort(&s_a, &s_b);
		free(s_b.array);
	}
	free(s_a.array);
	return (0);
}
