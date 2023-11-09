/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrottger <wrottger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:32:14 by wrottger          #+#    #+#             */
/*   Updated: 2023/07/14 11:25:54 by wrottger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

struct s_stacks{
	int		*a;
	size_t	a_size;
	int		*b;
	size_t	b_size;
	size_t	size;
};

void	*malloc_stacks(struct s_stacks *stacks, int argc);
void	sort_stacks(struct s_stacks stacks);
int		init_stacks(struct s_stacks *stacks, char **argv);
int		count_bits(size_t n);
int		get_bit(size_t bit, int num);
void	free_stacks(struct s_stacks stacks);
void	normalize_stacks(struct s_stacks *stacks);
void	print_stacks(struct s_stacks stacks);
void	pb(struct s_stacks *stacks);
void	pa(struct s_stacks *stacks);
void	ra(struct s_stacks *stacks);
void	swap(int *a, int *b);
void	sort_three(struct s_stacks stacks);
void	sort_middle(struct s_stacks stacks);
int		sorted(int	*stack, size_t len);

#endif
