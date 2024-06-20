/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:14:11 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/20 02:52:54 by jherzog          ###   ########.fr       */
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
	int	top;
	int	len;
	int	min;
	int	max;
	int	mid;
}	t_stack;

void	ft_print_stacks(int *s_a, int len);
char	*join_args(char **argv);
void	init_stacks(t_stack *stack_a, t_stack *stack_b);
void	create_stack_a(char *param, t_stack *stack_a);
void	find_mid(t_stack *stack_a);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);

void	error_handling(t_stack *stack_a);
bool	error_syntax(char *num);
bool	error_rep(t_stack *stack, int nbr);

bool	stack_a_sorted(t_stack *stack_a);
bool	stack_b_sorted(t_stack *stack_b);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);

void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

void	sort(t_stack *stack_a, t_stack *stack_b);

#endif
