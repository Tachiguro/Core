/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:47:19 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/10 18:28:34 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

static void	handle_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

static void	send_char(pid_t server_pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;

	i = 0;
	if (argc != 3)
		handle_error("Usage: ./client <server_pid> <message>");
	server_pid = (pid_t)ft_atoi(argv[1]);
	if (server_pid <= 0)
		handle_error("Invalid PID!");
	if (argv[2][0] == '\0')
		handle_error("Error: Message cannot be empty!");
	while (argv[2][i] != '\0')
	{
		send_char(server_pid, argv[2][i]);
		i++;
	}
	send_char(server_pid, '\n');
	return (0);
}
