/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 06:01:48 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/08 06:36:56 by jherzog          ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}


void	ft_sort_argv(int argc, char **argv)
{
	int		i;
	char	*temp;
	int		sorted;

	sorted = 0;
	while (++sorted < argc -1)
	{
		i = 0;
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				
				temp = (int *) malloc((ft_strlen(argv[i]) + 1) * sizeof(char));
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (1);
	i = 0;
	ft_sort_argv_tab(argc, argv);
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		if (i < argc - 1)
			write(1, "\n", 1);
	}
	write(1, "\n", 1);
	return (0);
}
