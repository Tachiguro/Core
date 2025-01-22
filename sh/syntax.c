/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:12:53 by jherzog           #+#    #+#             */
/*   Updated: 2025/01/23 00:16:13 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static bool	is_valid_char_in_pos(const char *l, int len)
{
	if (len == 0)
		return (true);
	if (l[0] == '<' || l[0] == '>' || l[0] == ')' || l[0] == '|' ||
		l[len - 1] == '<' || l[len - 1] == '>' || l[len - 1] == ')' ||
			l[len - 1] == '|')
		return (false);
	return (true);
}

bool	is_correct_syntax(const char *l)
{
	int	len;

	len = ft_strlen(l);
	if (!is_valid_char_in_pos(l, len))
			return (false);
	return (true);
}
