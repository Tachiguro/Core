/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jherzog <jherzog@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:47:53 by jherzog           #+#    #+#             */
/*   Updated: 2024/09/09 20:50:58 by jherzog          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int				bit_index = 0;
	static unsigned char	character = 0;

	(void)context;
	if (sig == SIGUSR1)
		character |= (1 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		ft_printf("%c", character);
		if (character == '\0')
			ft_printf("\n");
		bit_index = 0;
		character = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	handle_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		handle_error("Error: Unable to catch SIGUSR1");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		handle_error("Error: Unable to catch SIGUSR2");
	while (1)
		pause();
	return (0);
}
