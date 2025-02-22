/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:00:00 by isel-kha          #+#    #+#             */
/*   Updated: 2025/02/22 03:55:19 by isel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
#include <unistd.h>

t_data	g_data;

void	ft_handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	g_data.client_pid = info->si_pid;
	if (sig == SIGUSR2)
		g_data.c |= (1 << g_data.bit_position);
	g_data.bit_position++;
	if (g_data.bit_position == 8)
	{
		ft_putchar_fd(g_data.c, 1);
		g_data.c = 0;
		g_data.bit_position = 0;
	}
}

void	ft_setup_signals(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = ft_handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

void	ft_print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
}

int	main(void)
{
	g_data.c = 0;
	g_data.bit_position = 0;
	g_data.client_pid = 0;
	ft_print_pid();
	ft_setup_signals();
	while (1)
		pause();
	return (0);
}
