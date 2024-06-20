/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:50:54 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/20 02:43:00 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->array = NULL;
	stack_a->top = -1;
	stack_a->len = 0;
	stack_a->min = INT_MAX;
	stack_a->max = INT_MIN;
	stack_a->mid = 0;
	stack_b->array = NULL;
	stack_b->top = -1;
	stack_b->len = 0;
	stack_b->min = INT_MAX;
	stack_b->max = INT_MIN;
	stack_b->mid = 0;
}

static int	is_valid(t_stack *stack_a, char **strs, int i)
{
	int		nbr;

	nbr = 0;
	if (error_syntax(strs[i]))
		error_handling(stack_a);
	nbr = ft_atol(strs[i]);
	if (nbr > INT_MAX || nbr < INT_MIN || error_rep(stack_a, (int)nbr))
		error_handling(stack_a);
	return (nbr);
}

void	create_stack_a(char *argv, t_stack *stack_a)
{
	int		i;
	char	**strs;

	strs = ft_split(argv, ' ');
	if (!strs)
		exit(-1);
	while (strs[stack_a->len])
		stack_a->len++;
	i = stack_a->len - 1;
	stack_a->array = (int *)malloc(sizeof(int) * stack_a->len);
	if (!stack_a->array)
		exit(-1);
	while (i >= 0)
	{
		stack_a->array[++(stack_a->top)] = is_valid(stack_a, strs, i);
		if (stack_a->max < stack_a->array[stack_a->top])
			stack_a->max = stack_a->array[stack_a->top];
		if (stack_a->min > stack_a->array[stack_a->top])
			stack_a->min = stack_a->array[stack_a->top];
		i--;
	}
	find_mid(stack_a);
	free(strs);
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
