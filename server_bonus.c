/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarabog <mkarabog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:22:20 by mkarabog          #+#    #+#             */
/*   Updated: 2023/02/26 20:05:59 by mkarabog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	bit_left(int sig, siginfo_t *info, void *unused)
{
	int			binary;
	static int	result = 0;
	static int	bit = 7;

	(void)unused;
	if (sig == SIGUSR1)
		binary = 1;
	else
		binary = 0;
	result = result + (binary << bit);
	if (bit == 0)
	{
		if (result == 0)
			kill(info->si_pid, SIGUSR1);
		ft_printf("%c", result);
		bit = 7;
		result = 0;
	}
	else
		bit--;
}

int	main(void)
{
	int					pid;
	struct sigaction	client;	

	client.sa_sigaction = bit_left;
	client.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("PID = %d\n", pid);
	sigaction(SIGUSR1, &client, NULL);
	sigaction(SIGUSR2, &client, NULL);
	while (1)
		;
	return (0);
}
