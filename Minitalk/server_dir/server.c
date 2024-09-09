/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:47:53 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/09 20:12:29 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_printf("To much arguments!\n");
		exit(1);
	}
	if (!argv[0])
		exit(1);
	ft_printf("Server PID: %d\n", getpid());
	return (0);
}
