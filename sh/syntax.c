/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:12:53 by jherzog           #+#    #+#             */
/*   Updated: 2025/01/22 20:45:34 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

#define NOT_VALID_CHARS "<>&)|"

static bool	is_valid_char(const char c)
{
	if (ft_strchr(NOT_VALID_CHARS, c) != NULL)
		return (false);
	return (true);
}

static bool	is_quotes_even(const char *l)
{
	int	i;
	int	single_quotes;
	int	double_quotes;

	i = 0;
	single_quotes = 0;
	double_quotes = 0;
	while (l[i])
	{
		if (l[i] == '\'' && (i == 0 || l[i - 1] != '\\'))
			single_quotes++;
		if (l[i] == '\"' && (i == 0 || l[i - 1] != '\\'))
			double_quotes++;
		i++;
	}
	if (single_quotes % 2 != 0 || double_quotes % 2 != 0)
		return (false);
	return (true);
}

bool	is_correct_syntax(const char *l)
{
	int	i;
	int	len;

	i = 0;
	if (!l)
		print_error("Empty Command!\n");
	len = ft_strlen(l);
	if (len == 0)
		return (false);
	if (!is_valid_char(l[0]) || !is_valid_char(l[len - 1]))
			return (false);
	if (!is_quotes_even(l))
		return (false);
	// while (l[i] != '\0')
	// {
	// 	if ()
	// 	{
	// 		return (false);
	// 	}
		i++;
	// }
	return (true);
}
