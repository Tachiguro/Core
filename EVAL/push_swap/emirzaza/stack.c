/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirzaza <emirzaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:07:22 by emirzaza          #+#    #+#             */
/*   Updated: 2023/07/11 14:32:30 by emirzaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**free_split(char **split)
{
	int	j;

	j = 0;
	while (split[j])
		free(split[j++]);
	free(split[j]);
	free(split);
	return (NULL);
}

t_list	*handle_single_param(char	**argz)
{
	int		i;
	t_list	*stack_a;
	t_list	*temp;
	char	**input;

	input = ft_split(argz[1], ' ');
	stack_a = ft_lstnew(ft_atoi((input[0])));
	temp = stack_a;
	i = 1;
	while (input[i])
	{
		temp -> next = ft_lstnew(ft_atoi(input[i]));
		temp = temp -> next;
		i++;
	}
	free_split(input);
	return (stack_a);
}

t_list	*fill_stack(int argc, char	**argz)
{
	t_list	*stack_a;
	t_list	*temp;
	int		i;

	if (argc == 2)
		stack_a = handle_single_param(argz);
	else
	{
		stack_a = NULL;
		if (argz[1])
			stack_a = ft_lstnew(ft_atoi(argz[1]));
		temp = stack_a;
		i = 2;
		while (i < argc)
		{
			temp -> next = ft_lstnew(ft_atoi(argz[i++]));
			temp = temp -> next;
		}
	}
	return (stack_a);
}

static t_list	*get_next_min(t_list	**stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1)
				&& (!has_min || head->content < min->content))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	int		i;
	t_list	*head;

	i = 0;
	head = get_next_min(stack);
	while (head != NULL)
	{
		head -> index = i++;
		head = get_next_min(stack);
	}
}
