/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 05:56:52 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/08 05:59:48 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		write(1, &str[counter], 1);
		counter++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	while (--argc > 0)
	{
		ft_putstr(argv[argc]);
		if (argc - 1 > 0)
			write(1, "\n", 1);
	}
	write(1, "\n", 1);
	return (0);
}
