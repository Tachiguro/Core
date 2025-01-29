/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:21:34 by jherzog           #+#    #+#             */
/*   Updated: 2025/01/29 14:42:07 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int	main(void)
{
	char	*line;
	t_token	*head;

	line = NULL;
	head = NULL;
	using_history();
	while (1)
	{
		line = readline("$>");
		if (!line || !*line)
		{
			free(line);
			break ;
		}
		add_history(line);
		if (!is_correct_syntax(line))
			print_error("Syntax is not correct!");
		if (ft_strnstr(line, "exit", ft_strlen(line)))
			ft_exit(line);
		head = create_tokens(line);
		if (!head)
			print_error("Something is wrong... -> (!head)");
		print_tokens(head);
		free_tokens(head);
		free(line);
	}
	return (0);
}
