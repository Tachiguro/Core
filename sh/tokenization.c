/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:32:28 by jherzog           #+#    #+#             */
/*   Updated: 2025/01/25 23:02:03 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static bool	is_special_char(char c)
{
	if (c == '\'' || c == '\"' || c == '<' || c == '>' || c == '|' || c == '$')
		return (true);
	return (false);
}

static t_symbol	char_to_symbor(char c)
{
	if (c == '|')
		return (T_PIPE);
	if (c == '<')
		return (T_LESS_THAN);
	if (c == '>')
		return (T_GREATER_THAN);
	if (c == '$')
		return (T_DOLLAR);
	if (c == '\'')
		return (T_SINGLE_QUOTE);
	if (c == '\"')
		return (T_DOUBLE_QUOTE);
	if (c == '?')
		return (T_QUESTION_MARK);
	if (c == '~')
		return (T_TILDE);
	return (T_WORD);
}

static t_token	add_token(char *line)
{

}

t_token	*get_token(char *line)
{
	t_token	*head;
	int		i;
	bool	in_quotes;

	head = NULL;
	i = 0;
	in_quotes = false;
	while (line[i] != '\0')
	{
		if (is_special_char(line[i]))
		{

		}
		i++;
	}
	return (head);
}
