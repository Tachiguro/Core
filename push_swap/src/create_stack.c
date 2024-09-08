/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:50:54 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/08 21:45:04 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(t_stack *s_a, t_stack *s_b)
{
	s_a->array = NULL;
	s_a->chunks = NULL;
	s_a->chunks_len = 0;
	s_a->chunk_mid = 0;
	s_a->top = -1;
	s_a->len = 0;
	s_a->chunk_max = INT_MIN;
	s_a->max = INT_MIN;
	s_b->array = NULL;
	s_b->chunks = NULL;
	s_b->chunks_len = 0;
	s_b->chunk_mid = 0;
	s_b->top = -1;
	s_b->len = 0;
	s_b->chunk_max = INT_MIN;
	s_b->max = INT_MIN;
}

static int	is_valid(t_stack *s_a, char **strs, int i)
{
	long	nbr;

	nbr = 0;
	if (error_syntax(strs[i]))
		error_handling(s_a);
	nbr = ft_atol(strs[i]);
	if (nbr > INT_MAX || nbr < INT_MIN || error_rep(s_a, (int)nbr))
		error_handling(s_a);
	return ((int)nbr);
}

static void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	create_s_a(char *argv, t_stack *s_a)
{
	int		i;
	char	**strs;

	if (!argv || !argv[0])
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	strs = ft_split(argv, ' ');
	if (!strs)
		exit(-1);
	while (strs[s_a->len])
		s_a->len++;
	i = s_a->len - 1;
	s_a->array = (int *)malloc(sizeof(int) * s_a->len);
	if (!s_a->array)
		exit(-1);
	while (i >= 0)
	{
		s_a->top++;
		s_a->array[s_a->top] = is_valid(s_a, strs, i);
		i--;
	}
	free_strs(strs);
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
