/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:14:11 by jherzog           #+#    #+#             */
/*   Updated: 2024/05/20 21:21:52 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
// char	*stack_sort(int *stack_a, int stack_a_len);

void	swap_a(int *stack_a);
void	swap_b(int *stack_b);
void	swap_a_and_b(int *stack_a, int *stack_b);
void	push_a(int *stack_a, int top_a, int *stack_b, int top_b, int len);
void	push_a(int *stack_a, int top_a, int *stack_b, int top_b, int len);

void	ra(int *stack_a, int top_a, int len);
void	rb(int *stack_b, int top_b, int len);
void	rra(int *stack_a, int top_a, int len);
void	rrb(int *stack_b, int top_b, int len);


#endif
