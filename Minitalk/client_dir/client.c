/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:47:19 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/09 20:26:14 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error: Not enouth arguments!\n");
		ft_printf("Usage:\n\t>%s <server pid> \"message\"\n", argv[0]);
		return(1);
	}
	else if (argc > 2)
	{
		ft_printf("Error: Too much arguments!\n");
		ft_printf("Usage:\n\t>%s <server pid> \"message\"\n", argv[0]);
		return(1);
	}
	if (argv[1][0] == '\0')
	{
		ft_printf("Error: Empty string\n");
		ft_printf("Usage:\n\t>%s <server pid> \"message\"\n", argv[0]);
		return(1);
	}
	return (0);
}
