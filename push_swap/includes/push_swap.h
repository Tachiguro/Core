/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:14:11 by jherzog           #+#    #+#             */
/*   Updated: 2024/06/17 18:54:56 by jherzog          ###   ########.fr       */
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
void	print_stacks(t_stack *stack_a, t_stack *stack_b);

void	error_handling(t_stack *stack_a);
bool	error_syntax(char *num);
bool	error_rep(t_stack *stack, int nbr);

bool	stack_sorted(t_stack *stack);
void	s_a(t_stack *stack);
void	s_b(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	p_a(t_stack *stack_a, t_stack *stack_b);
void	p_b(t_stack *stack_a, t_stack *stack_b);
void	r_a(t_stack *stack_a);
void	r_b(t_stack *stack_b);

void	push_swap(t_stack *stack_a, t_stack *stack_b);

#endif
