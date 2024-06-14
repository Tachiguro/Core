/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:47:12 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/14 18:28:59 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	create_stack(char *param, int **stack_a)
{
	int		len;
	int		i;
	int		*stack;
	char	**strs;

	len = 0;
	i = 0;
	strs = ft_split(param, ' ');
	while (strs[len])
		len++;
	stack = (int *)malloc(sizeof(int) * len);
	if (!stack)
		exit(-1);
	while (i < len)
	{
		stack[i] = ft_atol(strs[i]);
		i++;
	}
	*stack_a = stack;
	free(strs);
	return (len);
}

char	*join_args(char **argv)
{
	char	*all_parametres;
	int		len;
	int		y;
	int		x;
	int		i;

	len = 0;
	y = 1;
	x = 0;
	i = 0;
	while (argv[y])
		len += ft_strlen(argv[y++]) + 1;
	all_parametres = (char *)malloc(sizeof(char) * len);
	if (!all_parametres)
		exit(-1);
	y = 0;
	while (argv[++y])
	{
		while (argv[y][x])
			all_parametres[i++] = argv[y][x++];
		all_parametres[i++] = ' ';
		x = 0;
	}
	all_parametres[++i] = '\0';
	return (all_parametres);
}

int	main(int argc, char **argv)
{
	char	*all_parameters;
	int		*stack_a;
	int		stack_a_len;

	stack_a_len = 0;
	stack_a = NULL;
	all_parameters = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	else if (argc == 2)
		stack_a_len = create_stack(argv[1], &stack_a);
	else
	{
		all_parameters = join_args(argv);
		stack_a_len = create_stack(all_parameters, &stack_a);
		free(all_parameters);
	}
	ft_print_stacks(stack_a, stack_a_len);
	free(stack_a);
}
