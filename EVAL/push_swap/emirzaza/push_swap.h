/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirzaza <emirzaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:48:20 by emirzaza          #+#    #+#             */
/*   Updated: 2023/07/11 14:32:37 by emirzaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>

int				swap(t_list **stack);
int				ft_error(char	*msg);
void			radix(t_list **stack_a, t_list	**stack_b);
void			sort(t_list	**stack_a, t_list	**stack_b);
void			sort_small(t_list	**stack_a, t_list	**stack_b);
int				is_sorted(t_list	**stack_a);
void			index_stack(t_list **stack);
t_list			*fill_stack(int argc, char	**argz);
int				calculate_distance(t_list	**stack_a, int index);
void			check_args(int argc, char **argz);
void			ft_clear_stack(t_list **lst);
char			**free_split(char **split);
int				sa(t_list **stack_a);
int				sb(t_list **stack_b);
int				ss(t_list **stack_a, t_list **stack_b);
int				pa(t_list **stack_a, t_list **stack_b);
int				pb(t_list **stack_a, t_list **stack_b);
int				ra(t_list **stack_a);
int				rb(t_list **stack_b);
int				rr(t_list **stack_a, t_list **stack_b);
int				rra(t_list **stack_a);
int				rrb(t_list **stack_b);
int				rrr(t_list **stack_a, t_list **stack_b);

#endif