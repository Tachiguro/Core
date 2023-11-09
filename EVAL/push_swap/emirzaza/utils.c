/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirzaza <emirzaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:15:13 by emirzaza          #+#    #+#             */
/*   Updated: 2023/07/13 15:30:35 by emirzaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_distance(t_list	**stack_a, int index)
{
	int		distance;
	t_list	*temp;

	temp = *stack_a;
	distance = 0;
	while (temp != NULL)
	{
		if (temp->index == index)
			break ;
		distance++;
		temp = temp->next;
	}
	return (distance);
}

int	ft_error(char	*msg)
{
	ft_putendl_fd(msg, 2);
	exit(-1);
}

void	ft_clear_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
