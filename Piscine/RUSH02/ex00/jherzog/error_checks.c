/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:39:45 by jherzog           #+#    #+#             */
/*   Updated: 2023/02/12 18:53:01 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	dict_found(char *path_2_dict)
{
	int fd;

	fd = open(path_2_dict, O_WRONLY);
	close(fd);
	return (fd);
}

int	check_number(char *number)
{
	long	i;

	i = 0;
	while(number[i] != '\0')
	{
		if (number[i] < '1' && number[i] > '9')
			return (-1);
		i++;
	}
	i = ft_atol(number);
	printf("i:%li\n",i);
	if (i == -1)
	{
		return (-1);
	}
	if (i < 0 || i > 4294967295)
		return (-1);
	return (0);
}