/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:39:14 by jherzog           #+#    #+#             */
/*   Updated: 2025/01/29 14:42:59 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static const char	*get_type_name(t_type type)
{
	if (type == T_WORD) return "T_WORD";
	if (type == T_PIPE) return "T_PIPE";
	if (type == T_IN) return "T_IN";
	if (type == T_OUT) return "T_OUT";
	if (type == T_APPEND) return "T_APPEND";
	return ("WRONG, SO WRONG!!!!!!\n");
}

void	print_tokens(t_token *head)
{
	int		token_number;
	t_token	*current;

	token_number = 1;
	current = head;
	while (current)
	{
		ft_printf("token %d: %s = %s\n", token_number, get_type_name(current->type), current->value);
		current = current->next;
		token_number++;
	}
}

void	free_tokens(t_token *head)
{
	t_token	*current;
	t_token	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
	head = NULL;
}
