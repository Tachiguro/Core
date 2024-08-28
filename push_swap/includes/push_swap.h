/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:14:11 by jherzog           #+#    #+#             */
/*   Updated: 2024/08/29 00:39:19 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*array;
	int	*chunks;
	int	chunks_len;
	int	chunk_mid;
	int	chunk_remainer;
	int	top;
	int	len;
	int	max;
	int	max_chunk;
}	t_stack;

char	*join_args(char **argv);
void	init_stacks(t_stack *s_a, t_stack *s_b);
void	create_s_a(char *param, t_stack *s_a);
int		find_max_chunk(t_stack *s_a, int chunk);
void	print_stacks(t_stack *s_a, t_stack *s_b);

void	error_handling(t_stack *s_a);
bool	error_syntax(char *num);
bool	error_rep(t_stack *stack, int nbr);

bool	s_a_sorted(t_stack *s_a);
bool	s_b_sorted(t_stack *s_b);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *s_a, t_stack *s_b);

void	pa(t_stack *s_a, t_stack *s_b);
void	pb(t_stack *s_a, t_stack *s_b);

void	ra(t_stack *s_a);
void	rb(t_stack *s_b);
void	rr(t_stack *s_a, t_stack *s_b);

void	rra(t_stack *s_a);
void	rrb(t_stack *s_b);
void	rrr(t_stack *s_a, t_stack *s_b);

void	sort(t_stack *s_a, t_stack *s_b);
void	sort_three(t_stack *s_a);
int		rrotate_to_max(t_stack *s_a, int target);
int		rrotate_to_mid(t_stack *s_a, int target);

#endif
