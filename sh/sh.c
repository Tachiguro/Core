/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:21:34 by jherzog           #+#    #+#             */
/*   Updated: 2025/01/22 20:57:47 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int	main(void)
{
	// const char	*line = "cd /var && (echo -n \"Listing directory contents: \" && ls -la | grep \"^d\" > dir_contents.txt && cat dir_contents.txt) || echo \"Failed to change directory or list contents\"";
	char	*line;

	line = NULL;
	using_history();
	while (1)
	{
		line = readline("$>");
		if (!is_correct_syntax(line))
			print_error("Not valid command!");
		if (ft_strnstr(line, "exit", 4))
		{
			free(line);
			exit(0);
		}
		free(line);
	}
	return (0);
}
