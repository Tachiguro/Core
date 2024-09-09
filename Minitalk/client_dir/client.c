/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:47:19 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/09 20:51:24 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

static void	handle_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

static void	send_signal(pid_t server_pid, char *message)
{
	int		i;
	char	c;
	int		bit;

	i = -1;
	while (message[++i] != '\0')
	{
		c = message[i];
		bit = 0;
		while (bit < 8)
		{
			if ((c >> bit) & 1)
			{
				if (kill(server_pid, SIGUSR1) == -1)
					handle_error("Failed to send SIGUSR1!");
			}
			else
			{
				if (kill(server_pid, SIGUSR2) == -1)
					handle_error("Failed to send SIGUSR2!");
			}
			bit++;
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
		handle_error("Usage: ./client <server_pid> \"message\"");
	server_pid = (pid_t)ft_atoi(argv[1]);
	if (server_pid <= 0)
		handle_error("Invalid PID!");
	if (argv[2][0] == '\0')
		handle_error("Error: Message cannot be empty!");
	send_signal(server_pid, argv[2]);
	return (0);
}
