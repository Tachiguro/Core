/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 05:48:59 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/08 05:55:48 by jherzog          ###   ########.fr       */
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
	int	i;

	if (argc == 1)
		return (1);
	i = 0;
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		if (i < argc - 1)
			write(1, "\n", 1);
	}
	write(1, "\n", 1);
	return (0);
}
